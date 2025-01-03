#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int main() 
{
    // const char *input_filename = "my_voice.wav";
    // const char *output_filename = "output_amplified.wav";

    // // Read the input WAV file
    // WAVFile *wavFile = readWavFile(input_filename);
    // if (!wavFile) 
    // {
    //     return 1; // Exit if reading fails
    // }

    // // Print the original WAV file info
    // printWavFileInfo(wavFile);

    // // Amplify the samples
    // float amplification_factor = 5;
    // amplifySamples(wavFile, amplification_factor);

    // // Save the amplified WAV file
    // writeWavFile(output_filename, wavFile);

    // // Free the WAV file memory
    // freeWavFile(wavFile);

    // //-----------------------------------------------------
    // int numSamples = SAMPLE_RATE * 3;  //3 seconds of audio

    // // 1. Generate sine wave (440 Hz)
    // FILE *file1 = fopen("sine_wave_440Hz.wav", "wb");
    // writeWavHeader(file1, numSamples);
    // generateSineWave(file1, 440, numSamples);  // 440 Hz
    // fclose(file1);
    // printf("Generated sine_wave_440Hz.wav\n");

    // // 2. Generate square wave (440 Hz)
    // FILE *file2 = fopen("square_wave_440Hz.wav", "wb");
    // writeWavHeader(file2, numSamples);
    // generateSquareWave(file2, 440, numSamples);  // 440 Hz
    // fclose(file2);
    // printf("Generated square_wave_440Hz.wav\n");

    // // 3. Generate white noise
    // FILE *file3 = fopen("white_noise.wav", "wb");
    // writeWavHeader(file3, numSamples);
    // generateWhiteNoise(file3, numSamples);
    // fclose(file3);
    // printf("Generated white_noise.wav\n");

    // // 4. Generate chirp (from 200 Hz to 1000 Hz)
    // FILE *file4 = fopen("chirp_wave.wav", "wb");
    // writeWavHeader(file4, numSamples);
    // generateChirp(file4, numSamples, 200, 1000);  // Frequency sweep from 200 Hz to 1000 Hz
    // fclose(file4);
    // printf("Generated chirp_wave.wav\n");

    //------------------------------------------------------
    const char *input_filename = "my_voice.wav";
    const char *output_filename_stretched = "output_stretched.wav";

    // Read input WAV file
    WAVFile *wavFile = readWavFile(input_filename);
    if (!wavFile) 
    {
        return EXIT_FAILURE; // Exit if reading fails
    }

    // Print original WAV file info
    printWavFileInfo(wavFile);

    // Apply time stretching and pitch shifting
    float stretch_factor = 1.5; // 1.5x slower playback (time stretch)
    timeStretch(wavFile, stretch_factor);

    // Save the modified WAV file
    writeWavFile(output_filename_stretched, wavFile);

    // Print modified WAV file info
    printWavFileInfo(wavFile);

    // Free WAV file memory
    freeWavFile(wavFile);

    return 0;
}

/*
A sample is neither a bit nor a byte on its own, 
but it represents an amplitude value of the audio signal at a specific point 
in time. The bit depth (e.g., 8-bit, 16-bit) defines how much information 
(in terms of bits) is used to represent each sample.


WAV File Info:
Number of Channels: 1
Sample Rate: 44100 Hz
Bits per Sample: 16
Data Size: 344064 bytes
Number of Samples: 172032
First 10 samples:
Sample 1: 79
Sample 2: 82
Sample 3: 70
Sample 4: 55
Sample 5: 42
Sample 6: 14
Sample 7: 21
Sample 8: 38
Sample 9: 64
Sample 10: 96

the data is the same as how i saved the wav file. Good.

Data Size = (Number of Samples) * (Number of Channels) * (Bits Per Sample / 8)
-------------------------------------------
say i have 
sample rate: 44100 Hz (samples per second)
duration: 5 sec
number of channels: 2
bits per sample: 16

number of samples = 44100 samples/sec * 5 sec = 220,500 samples
audio data size = 220,500 samples * 2 channels * (16 bits / 8 bits per byte) = 
881,000 bytes.


*/