/*Name : Veeresh G S 
Submission date : 25/01/2026
Project Name : Steganography
********************************************************************
 * Opeartions    : Encoding and Decoding
 * Description   :
 * This program demonstrates the concept of steganography where
 secret data is hidden inside an image using the Least Significant
 Bit (LSB) technique.
 *
 * Encoding  : Hides secret message bits inside the image pixels.
 * Decoding  : Extracts the hidden message from the stego-image.
 *
 ********************************************************************
/********************************************************************
 * The main function initializes sample image and secret data,
 calls encoding and decoding functions, and demonstrates the
 working of steganography
 *******************************************************************/
#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "decode.h"
#include "types.h"
OperationType check_operation_type(char *);

int main(int argc, char *argv[])
{
    //checking command arguements count
    if(argc>=4)
    {
        EncodeInfo encInfo;
        DecodeInfo decInfo;
        //call operation check function to check opeartion type
        //if command is -e return e_encode
        if(check_operation_type(argv[1])==e_encode)
        {
            //check all the arguements are valid are not if valid then receive e_success
            if(read_and_validate_encode_args(argv,&encInfo)==e_success)
            {
                //call encoding operation
                printf("\t\t\t##Encoding procedure started##\n");
                if((do_encoding(&encInfo))==e_success)
                {
                    printf("##Encoding successfully completed##\n");
                }
                else
                {
                    printf("##Encoding is not successfully completed##\n");
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        else if(check_operation_type(argv[1])==e_decode)
        {
            //check all the arguements are valid are not if valid then receive e_success
            if(read_and_validate_decode_args(argv,&decInfo)==e_success)
            {
                //call decoding operation
                printf("Reading and validating arguements is completed\n");
                printf("\t\t\t##Decoding procedure started##\n");
                if((do_decoding(argv,&decInfo))==e_success)
                {
                    printf("##Decoding successfully completed##\n");
                }
                else
                {
                    printf("##decoding is not completed\n");
                    return 0;
                }
            }
            else
            { 
                //some of the arguement extensiions are not valid so terminate program
                printf("Error: Invalid command-line arguments\n");
                return 0;   
            }
        }
        //command which is mention operation type is not valid 
        else if(check_operation_type(argv[1])==e_unsupported)
        {
            printf("Error: Invalid operation type\n");
            return 0;
        }
    }
    else
    {
        printf("Command arguements are not correct\n");
        printf("For help\nPass Arguements like\n");
        printf("Encode : \n./a.out -e beautiful.bmp secret.txt\n");
        printf("Decode : \n./a.out -d dest.bmp secretdata\n");
        return 0;
    }
}
OperationType check_operation_type(char *symbol)
{
    //if opeartion command arguement is -e say as do encode so return e_encode
    if(strcmp(symbol,"-e")==0)
    {
        return e_encode;
    }
    //if opeartion command arguement is -d say as do decode so return e_decode
    else if(strcmp(symbol,"-d")==0)
    {
        return e_decode;
    }
    //command arguement which is mention opeartion is not valid so return e_unsupported
    else
    {
        return e_unsupported;
    }
}
