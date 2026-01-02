#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"

int data[8192] = {0};
int contextStack[8192] = {0}, contextStackIndex = 0;
int opStack[8192] = {0}, opStackIndex = 0, opTemp = 0;
int lastBindDataIndex = 0;

int main() {
    contextStackIndex = 0;
    opStackIndex = 0;
    opTemp = 0;
    lastBindDataIndex = 0;

    //";"

    //"4"
    opStack[++opStackIndex] = opTemp = 0x00000004;

    //"SCAN"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"SCAN"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"ADD"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"SUB"
    opTemp = opStack[opStackIndex - 1] -= opStack[opStackIndex]; --opStackIndex;

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"MUL"
    opTemp = opStack[opStackIndex - 1] *= opStack[opStackIndex]; --opStackIndex;

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"DIV"
    opTemp = opStack[opStackIndex - 1] /= opStack[opStackIndex]; --opStackIndex;

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"MOD"
    opTemp = opStack[opStackIndex - 1] %= opStack[opStackIndex]; --opStackIndex;

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"SUB"
    opTemp = opStack[opStackIndex - 1] -= opStack[opStackIndex]; --opStackIndex;

    //"10"
    opStack[++opStackIndex] = opTemp = 0x0000000A;

    //"MUL"
    opTemp = opStack[opStackIndex - 1] *= opStack[opStackIndex]; --opStackIndex;

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"ADD"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"10"
    opStack[++opStackIndex] = opTemp = 0x0000000A;

    //"DIV"
    opTemp = opStack[opStackIndex - 1] /= opStack[opStackIndex]; --opStackIndex;

    //"ADD"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_X00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"_X00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"10"
    opStack[++opStackIndex] = opTemp = 0x0000000A;

    //"MOD"
    opTemp = opStack[opStackIndex - 1] %= opStack[opStackIndex]; --opStackIndex;

    //"ADD"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_X00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_Y00"
    opStack[++opStackIndex] = opTemp = data[0x00000010];

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    return 0;
}