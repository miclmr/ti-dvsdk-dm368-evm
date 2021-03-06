/* --COPYRIGHT--,BSD
 * Copyright (c) 2010, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <xdc/std.h>

#include "../appMain.h"

/******************************************************************************
 * usage
 ******************************************************************************
 *       Options:
 *       numFrames     Number of frames to process [Default: 100]
 *       startframe    First frame to write to disk [Default: 1]   
 *       benchmark     Print benchmarking information
 *       cache         Assume codecs input/output buffers are cached, perform
 *                     cache maintenance.   
 *       compandingLaw Companding Law for G711 and G726 [Default: 1] 
 *                     0=lin, 1=alaw, 2=ulaw 
 *       inFile        Name of input file to encode
 *       outFile       Name of output file containing raw PCM
 *       codecName     Name of codec to use
 *       engineName    Codec engine containing specified codec
 */

/* Arguments passed to application */
Args passedArgs = {
    100,         /* numFrames     */
    1,           /* startFrame    */
    FALSE,       /* benchmark     */
    TRUE,        /* cache */
    1,           /* compandingLaw */
};
        
/* String arguments */
static Char inFile[MAX_FILE_NAME_SIZE] = "";
static Char outFile[MAX_FILE_NAME_SIZE] = "";
static Char codecName[MAX_CODEC_NAME_SIZE] = "";
static Char engineName[MAX_ENGINE_NAME_SIZE] = "";

/******************************************************************************
 * parseArgs
 ******************************************************************************/
Void parseArgs(Args *argsp)
{
    if ((strncmp(codecName, "", 1) == 0) || 
        (strncmp(inFile, "", 1) == 0) || 
        (strncmp(outFile, "", 1) == 0)) {
        printf("Error: Bad codec or file names in arguments.\n");
        exit(EXIT_FAILURE);
    } 
    else {
        strncpy(argsp->inFile, inFile, MAX_FILE_NAME_SIZE);
        strncpy(argsp->outFile, outFile, MAX_FILE_NAME_SIZE);
        strncpy(argsp->engineName, engineName, MAX_ENGINE_NAME_SIZE);
        strncpy(argsp->codecName, codecName, MAX_CODEC_NAME_SIZE);
    }

    return;
}
