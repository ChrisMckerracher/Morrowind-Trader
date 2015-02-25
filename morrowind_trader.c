#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define top_const 320
#define count_item 4
#define NPCO_item 32
#define HEADER 8

//all headers are defined by byte size
//top_const deals with bytes up to MAST
//count_item is the size of an int, the count for an item
//NPCO_item is the size of one item, ex ring_vampiric_unique
//HEADER is just any preceeding header, like NPCO

//file data
struct fdata {
    unsigned char * bytes;
    int size; //size of unsigned char  
}

void copy_data(FILE * read_file, FILE * write_file, num_bytes);
void write_data(FILE * write_file, struct fdata data);
struct fdata read_data(FILE * read_file, int size); 
void find_keyword(char * readbuffer, unsigned char * string);
void read_wrapper(FILE * read_file, FILE * write_file);

//read_wrapper will be the wrapper for reading and writing to file
//use unsigned char for file type

//things to consider:
//-i'll only need to concatenate the past read with current
//as long as buffer is big enough
//ex: buffer ends at NPC
//next starts with 0
//i concatenate it, and bam NPC0
//-also, once NPC0 or whatever header im looking for is found
//i should probably change read buffer size so i can properly search
//for the next thing
//-when concatenating and finding the string,
//part of the next thing i read may have been in the second part
//of the concatenation
//so consider 2 buffers
//total_buffer, with the past buffer and this buffer and
//current_buffer, with the last read

void write_data(FILE * write_file, struct fdata data); 
    //attempts an fwrite. returns 0 if sucessfull, or 1 in
    //an event of a failure
    int success_checker;
    success_checker = fwrite(data.bytes, 1, data.size, write_file);

    if (success_checker != data.size){
    printf("something went wrong with writing to new save file");
    exit(1);
    }
}

struct fdata read_data(FILE * read_file, int size){
    //consider shrinking data.data if size is smaller than expected
    struct fdata data;
    data.data = malloc(size);
    data.size = fread(fdata.data, 1, size, read_file);

    return data;
}

void copy_data(FILE * read_file, FILE * write_file, int num_bytes){
//make use of the above write_data function
    struct fdata data = read_data(read_file, num_bytes);
    
    write_data(write_file, data);   
}



