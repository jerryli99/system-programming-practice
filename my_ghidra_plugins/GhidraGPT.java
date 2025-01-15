//This is a plugin code using ChatGPT
//@author jerryli99
//@description This is a script for using chatgpt
//@category AI Integration
//@keybinding 
//@menupath 
//@toolbar 
//@runtime Java

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.flatapi.FlatDecompilerAPI;
import ghidra.app.services.CodeViewerService;
import ghidra.program.flatapi.FlatProgramAPI;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Program;
import ghidra.program.model.address.Address;
import ghidra.program.util.ProgramLocation;
import java.net.URI;
import java.net.http.*;

public class GhidraGPT extends GhidraScript {

    private static final String API_KEY = ""; //your API key here, or just use env variable will do.
    private static final String GPT_API_URL = "https://api.openai.com/v1/chat/completions"; // GPT-4 endpoint
    private static final String MODEL_NAME = "gpt-4o-mini"; //the GPT model you're using

    private CodeViewerService m_cvs;

    @Override
    protected void run() throws Exception {
        // Initialize the required service
        m_cvs = state.getTool().getService(CodeViewerService.class);

        //decompile the current function
        String decompiledCode = decompileCurrentFunction();
        if (decompiledCode == null) {
            println("Failed to decompile the current function.");
            return;
        }

        //send the decompiled code to GPT-4 API for summarization
        String summaryResponse = getSummaryFromGPT(decompiledCode);
        println(summaryResponse);


        // Insert comments in the code
        // insertComments(summaryResponse);
    }

    /**
     * Decompiles the function at the current cursor location.
     *
     * @return Decompiled function code as a String, or null if an error occurs.
     */
    private String decompileCurrentFunction() {
        ProgramLocation progLoc = m_cvs.getCurrentLocation();
        Program prog = progLoc.getProgram();
        FlatProgramAPI programApi = new FlatProgramAPI(prog);
        FlatDecompilerAPI decompiler = new FlatDecompilerAPI(programApi);

        //get the function at the current location
        Function func = programApi.getFunctionContaining(progLoc.getAddress());
        if (func == null) {
            println("No function found at the current location.");
            return null;
        }

        //decompile the function
        try {
            return decompiler.decompile(func);
        } catch (Exception e) {
            println("Decompilation failed: " + e.getMessage());
            return null;
        }
    }

    /**
     * Calls GPT-4 API to summarize the decompiled code.
     *
     * @param decompiledCode The decompiled code to summarize.
     * @return The API response as a string.
     */
    private String getSummaryFromGPT(String decompiledCode) {
        String jsonPayload = "{"
                + "\"model\": \"" + MODEL_NAME + "\","
                + "\"messages\": ["
                + "    {"
                + "        \"role\": \"system\","
                + "        \"content\": \"You are a useful code analyzer. Please help me summarize what this disassembled C code does and if possible tell me what this can be used for based on the pattern. For the response, follow the format: summary: answer_here, other: answer_here\""
                + "    },"
                + "    {"
                + "        \"role\": \"user\","
                + "        \"content\": \"" + escapeJson(decompiledCode) + "\""
                + "    }"
                + "],"
                + "\"max_tokens\": 250,"
                + "\"temperature\": 0.7"
                + "}";

        try {
            //create HTTP client
            HttpClient client = HttpClient.newHttpClient();

            //build HTTP request
            HttpRequest request = HttpRequest.newBuilder()
                .uri(new URI(GPT_API_URL))
                .header("Content-Type", "application/json")
                .header("Authorization", "Bearer " + API_KEY)
                .POST(HttpRequest.BodyPublishers.ofString(jsonPayload))
                .build();
            
            HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());

            if (response.statusCode() == 200) {
                return response.body();
            }

            println("API call failed with status code: " + response.statusCode());
            return "Failed to get summary.";
        } catch (Exception e) {
            println("Error during API call: " + e.getMessage());
            return "Error during API call.";
        }
    }

    /**
     * Escapes special characters in JSON strings.
     *
     * @param input The input string to escape.
     * @return Escaped JSON string.
     */
    private String escapeJson(String input) {
        return input.replace("\\", "\\\\")
                    .replace("\"", "\\\"")
                    .replace("\n", "\\n")
                    .replace("\r", "\\r");
    }
}

//feel free to add json libraries or OpenAI libraries and then do stuff you want
//below.....
//e.g. after you extracted the json fields, you can try this one: (add the summary as comments)
private void insertComments(String commentText) {
    ProgramLocation progLoc = m_cvs.getCurrentLocation();
    Program prog = progLoc.getProgram();
    FlatProgramAPI programApi = new FlatProgramAPI(prog);

    // Get the address of the current function
    Address funcAddress = progLoc.getAddress();
    Function func = programApi.getFunctionContaining(funcAddress);

    if (func != null) {
        Address entryPoint = func.getEntryPoint();

        // Add a plate comment at the function entry point
        programApi.setPlateComment(entryPoint, "GPT Summary: " + commentText);
        println("Comment added at the function entry point.");
    } else {
        println("No function found to add comments.");
    }
}
