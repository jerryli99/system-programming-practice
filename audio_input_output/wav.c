#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "wav.h"

/**
 * @brief Read the wav file.
 * 
 * @param filename const char pointer type.
 * 
 * @return WAVEFile pointer type.
 */
WAVFile* readWavFile(const char *filename) 
{
    FILE *file = fopen(filename, "rb");
    if (!file) 
    {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the WAVFile structure
    WAVFile *wavFile = (WAVFile*)malloc(sizeof(WAVFile));
    if (!wavFile) 
    {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return NULL;
    }

    //read the WAV header
    fread(&wavFile->header, sizeof(WAVHeader), 1, file);

    //check for valid WAV file format
    if (wavFile->header.riff[0] != 'R' || 
        wavFile->header.riff[1] != 'I' || 
        wavFile->header.riff[2] != 'F' || 
        wavFile->header.riff[3] != 'F') 
    {
        fprintf(stderr, "Invalid WAV file format.\n");
        fclose(file);
        free(wavFile);
        return NULL;
    }

    if (wavFile->header.wave[0] != 'W' || 
        wavFile->header.wave[1] != 'A' || 
        wavFile->header.wave[2] != 'V' || 
        wavFile->header.wave[3] != 'E') 
    {
        fprintf(stderr, "Invalid WAV file format.\n");
        fclose(file);
        free(wavFile);
        return NULL;
    }

    //skip the header and read the audio data
    fseek(file, sizeof(WAVHeader), SEEK_SET);

    //calculate number of samples
    wavFile->num_samples = wavFile->header.data_size / wavFile->header.block_align;

    //allocate memory for the audio data
    wavFile->data = (int16_t*)malloc(wavFile->header.data_size);
    if (wavFile->data == NULL) 
    {
        fprintf(stderr, "Memory allocation failed for audio data.\n");
        fclose(file);
        free(wavFile);
        return NULL;
    }

    //read the audio data
    fread(wavFile->data, wavFile->header.data_size, 1, file);

    fclose(file);
    return wavFile;
}

/**
 * @brief based on the read wav file function, pass the data (including header)
 *        to this function, then create a new wav file, save the processed wav
 *        data like amplify sample in there. The header remains unchanged.
 *        This function can be improved or simply rewritten. Depends.
 * 
 * @param filename const char pointer type.
 * @param wavFile WAVFile pointer type.
 * 
 * @return void. Show stderror if could not open wav file.
 */
void writeWavFile(const char *filename, WAVFile *wavFile) 
{
    if (wavFile == NULL) 
    {
        printf("Invalid WAV file.\n");
        return;
    }

    FILE *file = fopen(filename, "wb");
    if (file == NULL) 
    {
        fprintf(stderr, "Could not open file %s for writing.\n", filename);
        return;
    }

    // Write the WAV header
    fwrite(&wavFile->header, sizeof(WAVHeader), 1, file);

    // Write the audio data
    fwrite(wavFile->data, wavFile->header.data_size, 1, file);

    fclose(file);
    printf("WAV file saved as %s\n", filename);
}


/**
 * @brief free the memory used by the WAVFile struct.
 * 
 * @param wavFile a WAVFile pointer type.
 * 
 * @return void.
 */
void freeWavFile(WAVFile *wavFile) 
{
    if (wavFile != NULL) 
    {
        if (wavFile->data != NULL) 
        {
            free(wavFile->data);
        }
        free(wavFile);
    }
}

/**
 * @brief print the meta data from the wav file header, including #channels, 
 *        sample rate, bits/sample, data size, and #samples.
 * 
 * @param wavFile WAVFile pointer type.
 * 
 * @return void.
 * 
 */
void printWavFileInfo(WAVFile *wavFile) 
{
    if (wavFile == NULL) 
    {
        return;
    }

    printf("WAV File Info:\n");
    printf("Number of Channels: %d\n", wavFile->header.num_channels);
    printf("Sample Rate: %d Hz\n", wavFile->header.sample_rate);
    printf("Bits per Sample: %d\n", wavFile->header.bits_per_sample);
    printf("Data Size: %u bytes\n", wavFile->header.data_size);
    printf("Number of Samples: %d\n", wavFile->num_samples);

    // //extra here: print first 10 samples
    // printf("First 10 samples:\n");
    // for (int i = 0; i < 10 && i < wavFile->num_samples; ++i) 
    // {
    //     printf("Sample %d: %d\n", i + 1, wavFile->data[i]);
    // }
}

/**
 * @brief this function will make the sound in wav file louder.
 * 
 * @param wavFile WAVFile pointer type
 * @param factor float type, the number of times to scale the samples.
 * 
 * @return void. Print stderror if wav is invalid.
 */
void amplifySamples(WAVFile *wavFile, float factor)
{
    if (wavFile == NULL || wavFile->data == NULL) 
    {
        fprintf(stderr, "Invalid WAV file.\n");
        return;
    }

    for (int i = 0; i < wavFile->num_samples; ++i) 
    {
        int amplified_sample = wavFile->data[i] * factor;

        //clamp the amplified sample to the valid range
        if (amplified_sample > INT16_MAX) 
        {
            wavFile->data[i] = INT16_MAX;
        } 
        else if (amplified_sample < INT16_MIN) 
        {
            wavFile->data[i] = INT16_MIN;
        } 
        else 
        {
            wavFile->data[i] = (int16_t)amplified_sample;
        }
    }
}

//----------------------------------------------------------------
/**
 * @brief Unlike the writeWavFile function above, this function is used for 
 *        generating sounds, and to created wav file from scratch, we need to 
 *        write the wav file header from scratch, hence the name writeWavHeader.
 *        The macros: NUM_CHANNELS, BITS_PER_SAMPLE, SAMPLE_RATE are defined in 
 *        the wav.h file.
 * 
 * @param file FILE pointer type.
 * @param numSamples int type.
 * 
 * @return void. 
 * 
 */
void writeWavHeader(FILE *file, int numSamples) {
    WAVHeader header = {0};
    memcpy(header.riff, "RIFF", 4);
    header.file_size = 36 + numSamples * NUM_CHANNELS * (BITS_PER_SAMPLE / 8);
    memcpy(header.wave, "WAVE", 4);

    memcpy(header.fmt, "fmt ", 4);
    header.fmt_size = 16;
    header.audio_format = 1;  // PCM
    header.num_channels = NUM_CHANNELS;
    header.sample_rate = SAMPLE_RATE;
    header.byte_rate = SAMPLE_RATE * NUM_CHANNELS * (BITS_PER_SAMPLE / 8);
    header.block_align = NUM_CHANNELS * (BITS_PER_SAMPLE / 8);
    header.bits_per_sample = BITS_PER_SAMPLE;

    memcpy(header.data, "data", 4);
    header.data_size = numSamples * NUM_CHANNELS * (BITS_PER_SAMPLE / 8);

    fwrite(&header, sizeof(header), 1, file);
}

/**
 * @brief generate sine waves
 * 
 * @param file FILE pointer type
 * @param frequency integer type
 * @param numSamples integer type
 * 
 * @return void. 
 * 
 */
void generateSineWave(FILE *file, int frequency, int numSamples) {
    for (int i = 0; i < numSamples; i++) {
        double sample = AMPLITUDE * sin(2 * M_PI * frequency * i / SAMPLE_RATE);
        int16_t sampleInt = (int16_t)(sample);
        fwrite(&sampleInt, sizeof(int16_t), 1, file);
    }
    return;
}

/**
 * @brief generate a square wave tone
 * 
 * @param file FILE pointer type
 * @param frequency integer type
 * @param numSamples integer type
 * 
 * @return void.
 */
void generateSquareWave(FILE *file, int frequency, int numSamples) {
    for (int i = 0; i < numSamples; i++) {
        double sample = (i % (SAMPLE_RATE / frequency) < (SAMPLE_RATE / (2 * frequency))) ? AMPLITUDE : -AMPLITUDE;
        int16_t sampleInt = (int16_t)(sample);
        fwrite(&sampleInt, sizeof(int16_t), 1, file);
    }
    return;
}

/**
 * @brief generate white noise
 * 
 * @param file FILE pointer type
 * @param numSamples integer type
 * 
 * @return void.
 */
void generateWhiteNoise(FILE *file, int numSamples) {
    for (int i = 0; i < numSamples; i++) {
        int16_t sample = (rand() % (2 * AMPLITUDE)) - AMPLITUDE;
        fwrite(&sample, sizeof(int16_t), 1, file);
    }
}

/**
 * @brief generate a simple chirp (frequency sweep)
 * 
 * @param file FILE pointer type 
 * @param numSamples integer type
 * @param frequencyStart integer type
 * @param frequencyEnd integer type
 * 
 * @return void.
 */
void generateChirp(FILE *file, int numSamples, int frequencyStart, int frequencyEnd) {
    for (int i = 0; i < numSamples; i++) {
        double frequency = frequencyStart + (double)(frequencyEnd - frequencyStart) * i / numSamples;
        double sample = AMPLITUDE * sin(2 * M_PI * frequency * i / SAMPLE_RATE);
        int16_t sampleInt = (int16_t)(sample);
        fwrite(&sampleInt, sizeof(int16_t), 1, file);
    }
}


/**
 * @todo need to improve this I guess...
 * 
 * @brief In audio production, time stretching refers to a form of audio 
 *        processing that extends or contracts the duration of a sample or sound 
 *        without changing its pitch or tonal characteristics.
 * 
 * @param wavFile WAVFile pointer type
 * @param stretch_factor float type
 * 
 * @return void.
 */
void timeStretch(WAVFile *wavFile, float stretch_factor) 
{
    if ((wavFile == NULL) || (wavFile->data == NULL)) 
    {
        fprintf(stderr, "Invalid WAV file.\n");
        return;
    }

    //calculate new number of samples
    int new_num_samples = (int)(wavFile->num_samples * stretch_factor);

    //allocate memory for new audio data
    int16_t *new_data = (int16_t *)malloc(new_num_samples * sizeof(int16_t));
    if (!new_data) 
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    //resample using linear interpolation
    for (int i = 0; i < new_num_samples; ++i) 
    {
        float orig_index = i / stretch_factor;
        int index_low = (int)floor(orig_index);
        int index_high = index_low + 1;

        //clamp indices to valid range
        if (index_high >= wavFile->num_samples) 
        {
            index_high = wavFile->num_samples - 1;
        }

        float weight_high = orig_index - index_low;
        float weight_low = 1.0f - weight_high;

        //interpolate samples
        new_data[i] = (int16_t)(wavFile->data[index_low] * weight_low +
                                wavFile->data[index_high] * weight_high);
    }

    //update WAVFile structure
    free(wavFile->data);
    wavFile->data = new_data;
    wavFile->num_samples = new_num_samples;
    wavFile->header.data_size = new_num_samples * sizeof(int16_t);
    wavFile->header.file_size = wavFile->header.data_size + sizeof(WAVHeader) - 8;
}