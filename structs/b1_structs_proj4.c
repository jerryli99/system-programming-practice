#include <stdio.h>

typedef struct country_codes_
{
    char *country;
    int code;
} CountryCodes;

int main(void) 
{
    const CountryCodes country_codes[] =
    {{"Argentina",            54}, {"Bangladesh",     889},
     {"Brazil",               55}, {"Burma (Myanmar)", 95},
     {"China",                86}, {"Colombia",        57},
     {"Congo, Dem. Rep. of", 243}, {"Egypt",           20},
     {"Ethiopia",            251}, {"France",          33},
     {"Germany",              49}, {"India",           91},
     {"Indonesia",            62}, {"Iran",            98},
     {"Italy",                39}, {"Japan",           81},
     {"Mexico",               52}, {"Nigeria",        234},
     {"Pakistan",             92}, {"Philippines",     63},
     {"Poland",               48}, {"Russia",           7},
     {"South Africa",         27}, {"South Korea",     82},
     {"Spain",                34}, {"Sudan",          249},
     {"Thailand",             66}, {"Turkey",          90},
     {"Ukraine",             380}, {"United Kingdom",  44},
     {"United States",         1}, {"Vietnam",         84}};

    int code_size = sizeof(country_codes) / sizeof(country_codes[0]);
    int input_code;

    printf("Enter a country code: ");
    scanf("%d", &input_code);

    for (int index = 0; index < code_size; index++) 
    {
        if (country_codes[index].code == input_code) 
        {
            printf("Country code %d is for %s\n", input_code, country_codes[index].country);
        } 
        else 
        { 
            if (index == (code_size - 1)) 
            {
                printf("No matching country code.\n");
            }
        }
    }
    
    return (0);
}