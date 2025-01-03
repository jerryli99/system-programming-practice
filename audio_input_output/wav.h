#include <stdint.h>

//the WAV header structure
#pragma pack(push, 1)
typedef struct {
    char riff[4];             //"RIFF" string
    uint32_t file_size;       //size of the rest of the file after the first 8 bytes
    char wave[4];             //"WAVE" string
    char fmt[4];              //"fmt " string
    uint32_t fmt_size;        //size of the format chunk
    uint16_t audio_format;    //audio format (1 for PCM)
    uint16_t num_channels;    //number of channels
    uint32_t sample_rate;     //sample rate (samples per second)
    uint32_t byte_rate;       //byte rate (sampleRate * numChannels * bitsPerSample / 8)
    uint16_t block_align;     //block alignment (numChannels * bitsPerSample / 8)
    uint16_t bits_per_sample; //bits per sample (usually 16 or 8)
    char data[4];             //"data" string
    uint32_t data_size;       //size of the data chunk
} WAVHeader;
#pragma pack(pop)

/*
#pragma pack(push, 1):
Saves the current packing alignment on a stack.
Sets the packing alignment to 1 byte (no padding).

#pragma pack(pop):
Restores the previous packing alignment from the stack
*/

typedef struct {
    WAVHeader header;  //wAV header
    int16_t *data;     //audio data (PCM samples)
    int num_samples;  
} WAVFile;

WAVFile* readWavFile(const char *filename);
void writeWavFile(const char *filename, WAVFile *wavFile);
void freeWavFile(WAVFile *wavFile);
void printWavFileInfo(WAVFile *wavFile);
void amplifySamples(WAVFile *wavFile, float factor);

//-------------------------------------------------------------------

#define SAMPLE_RATE 44100   // Standard sample rate
#define NUM_CHANNELS 1      // Mono sound
#define BITS_PER_SAMPLE 16  // 16-bit depth
#define AMPLITUDE 3000      // Amplitude for the sound

void writeWavHeader(FILE *file, int numSamples);
void generateSineWave(FILE *file, int frequency, int numSamples);
void generateSquareWave(FILE *file, int frequency, int numSamples);
void generateWhiteNoise(FILE *file, int numSamples);
void generateChirp(FILE *file, int numSamples, int frequencyStart, int frequencyEnd);
void timeStretch(WAVFile *wavFile, float stretch_factor);