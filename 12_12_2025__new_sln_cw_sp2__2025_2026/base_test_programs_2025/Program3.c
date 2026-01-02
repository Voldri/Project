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

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"WHILE"
LABEL__WHILE_00007FF7A873B8C8:

    //"_C00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"!>"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] >= opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "WHILE")
    if (opTemp == 0) goto LABEL__AFTER_WHILE_00007FF7A873B8C8;

    //"_C00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"_C00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"MUL"
    opTemp = opStack[opStackIndex - 1] *= opStack[opStackIndex]; --opStackIndex;

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_C00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"ADD"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //end of while
    goto LABEL__WHILE_00007FF7A873B8C8;
LABEL__AFTER_WHILE_00007FF7A873B8C8:

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"20"
    opStack[++opStackIndex] = opTemp = 0x00000014;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"WHILE"
LABEL__WHILE_00007FF7A8744A40:

    //"_C00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"!>"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] >= opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "WHILE")
    if (opTemp == 0) goto LABEL__AFTER_WHILE_00007FF7A8744A40;

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"WHILE"
LABEL__WHILE_00007FF7A8748048:

    //"_X00"
    opStack[++opStackIndex] = opTemp = data[0x00000010];

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"!>"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] >= opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "WHILE")
    if (opTemp == 0) goto LABEL__AFTER_WHILE_00007FF7A8748048;

    //"_Y00"
    opStack[++opStackIndex] = opTemp = data[0x00000014];

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"ADD"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"20"
    opStack[++opStackIndex] = opTemp = 0x00000014;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"_X00"
    opStack[++opStackIndex] = opTemp = data[0x00000010];

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"ADD"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //end of while
    goto LABEL__WHILE_00007FF7A8748048;
LABEL__AFTER_WHILE_00007FF7A8748048:

    //"_C00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"ADD"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //end of while
    goto LABEL__WHILE_00007FF7A8744A40;
LABEL__AFTER_WHILE_00007FF7A8744A40:

    //null statement (non-context)

    //"_Y00"
    opStack[++opStackIndex] = opTemp = data[0x00000014];

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    return 0;
}