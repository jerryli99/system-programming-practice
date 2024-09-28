/*
This program begins by displaying the address of its own main function as well 
as the address of one of its variables. This will give the user a clue as to 
which areas of memory can be probed. The program next prompts the user to enter
an address (in the form of a hexadecimal integer) plus thhe number of bytes to
view. The program then displays a block of bytes of the chosen length, starting 
at the specified address.

Bytes are displayed in groups of 10 (except for the last group, which may have
fewer than 10 bytes). The address of a group of bytes is displayed at the 
beginning of a line, followed by the bytes in the group (displayed as 
hexadecimal numbers), followed by the same bytes displayed as characters. 
Only printing characters will be displayed; other characters will be shown as 
periods.

We will assume that int values are stored using 32 bits and that addresses are 
also 32 bits long. Addresses are displayed in hexadecimal, as is customary.

*/
// #include <stdio.h>
// #include <ctype.h>

// typedef unsigned char BYTE;

// int main(void)
// {
//     unsigned int addr;
//     int index, num_of_bytes;
//     BYTE *byte_ptr;

//     printf("Address of main function: %x\n", (unsigned int) main);
//     printf("Address of addr variable: %x\n", (unsigned int) &addr);
//     printf("\nEnter a (hex) address (no need to put the 0x.. in front): ");
//     scanf("%x", &addr);
//     printf("Enter number of bytes to view: ");
//     scanf("%d", &num_of_bytes);

//     printf("\n");
//     printf(" Address                    Bytes                    Characters\n");
//     printf(" -------   ---------------------------------------   ----------\n");

//     byte_ptr = (BYTE *) addr;
//     for (; num_of_bytes > 0; num_of_bytes -= 10) 
//     {
//         printf("%8X  ", (unsigned int) byte_ptr);
        
//         for (index = 0; (index < 10) && (index < num_of_bytes); index++)
//         {
//             printf("%.2X ", *(byte_ptr + index));
//         }

//         for (; index < 10; index++)
//         {
//             printf("    ");
//         }
        
//         printf(" ");

//         for (index = 0; (index < 10) && (index < num_of_bytes); index++)
//         {
//             BYTE ch = *(byte_ptr + index);
//             if (!isprint(ch))
//             {
//                 ch = '.';
//             }
//             printf("%c", ch);
//         }
//         printf("\n");
//         byte_ptr += 10;
//     }


//     return (0);
// }

//this is just messing around /proc/<pid>/mem stuff.
/*
pread() reads up to count bytes from file descriptor fd at offset
offset (from the start of the file) into the buffer starting at buf.  
The file offset is not changed.

what does snprintf mean?
The snprintf is a predefined library function of the stdio. h header file, 
which redirects the output of the standard printf() function to other buffers. 
The snprint() function is used to format the given strings into a series of 
characters or values in the buffer area.

The functions dprintf() and vdprintf() (as found in the glibc2 library) are 
exact analogs of fprintf(3) and vfprintf(3), except that they output to a 
file descriptor fd instead of to a stdio stream.

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define MAX_CAPTURE_SIZE 0x100000  // 1MB

void print_memory_layout(int pid, const char *output_file) 
{
    char maps_filename[256];
    char mem_filename[256];
    char line[256];
    unsigned long start, end;
    int mem_fd, out_fd;
    unsigned char buffer[16];  // Buffer to read memory
    ssize_t bytes_read;
    unsigned long total_bytes_read = 0;

    // Construct the filenames for /proc/[pid]/maps and /proc/[pid]/mem
    snprintf(maps_filename, sizeof(maps_filename), "/proc/%d/maps", pid);
    snprintf(mem_filename, sizeof(mem_filename), "/proc/%d/mem", pid);

    // Open the /proc/[pid]/maps file
    FILE *maps_file = fopen(maps_filename, "r");
    if (!maps_file) 
    {
        perror("Failed to open maps file");
        fclose(maps_file);
        exit(EXIT_FAILURE);
    }

    // Open the /proc/[pid]/mem file
    mem_fd = open(mem_filename, O_RDONLY);
    if (mem_fd == -1) 
    {
        perror("Failed to open mem file");
        fclose(maps_file);
        exit(EXIT_FAILURE);
    }

    // Open the output file
    //Oh! See this thing? 
    //The bits representing O_WRONLY, O_CREAT, O_TRUNC will be set.
    //We learned this in this chapter 20!! setting multiple bits.
    out_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out_fd == -1) 
    {
        perror("Failed to open output file");
        fclose(maps_file);
        close(mem_fd);
        exit(EXIT_FAILURE);
    }

    // Write the header to the output file
    dprintf(out_fd, "Memory Layout of PID %d:\n", pid);
    dprintf(out_fd, "=========================================\n");
    dprintf(out_fd, "Address Range                              Bytes                                 Characters\n");
    dprintf(out_fd, "---------------------------------------------------------------------------------------------\n");

    // Read each line of the maps file to get memory regions
    while (fgets(line, sizeof(line), maps_file) && 
          (total_bytes_read < MAX_CAPTURE_SIZE)) 
    {
        if (sscanf(line, "%lx-%lx", &start, &end) == 2) 
        {
            lseek(mem_fd, start, SEEK_SET);

            for (unsigned long addr = start; 
                (addr < end) && (total_bytes_read < MAX_CAPTURE_SIZE); 
                addr += sizeof(buffer)) 
            {
                bytes_read = pread(mem_fd, buffer, sizeof(buffer), addr);
                if (bytes_read <= 0) 
                {
                    break;
                }

                total_bytes_read += bytes_read;

                // Print the address range
                dprintf(out_fd, "%08lx-%08lx  ", addr, addr + bytes_read);

                // Print the bytes in hexadecimal
                for (int index = 0; index < bytes_read; index++) 
                {
                    dprintf(out_fd, "%02x ", buffer[index]);
                }

                // Pad the last line if it's less than the buffer size
                for (int index = bytes_read; index < sizeof(buffer); index++) 
                {
                    dprintf(out_fd, "   ");
                }

                // Print the corresponding characters
                dprintf(out_fd, "  ");
                for (int index = 0; index < bytes_read; index++) 
                {
                    dprintf(out_fd, "%c", isprint(buffer[index]) ? buffer[index] : '.');
                }

                dprintf(out_fd, "\n");

                if (total_bytes_read >= MAX_CAPTURE_SIZE) 
                {
                    break;
                }
            }
        }
    }

    // Close the files
    fclose(maps_file);
    close(mem_fd);
    close(out_fd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pid> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int pid = atoi(argv[1]);

    print_memory_layout(pid, argv[2]);

    return EXIT_SUCCESS;
}
