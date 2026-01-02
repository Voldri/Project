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

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"SCAN"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"IF"

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"!<"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] <= opStack[opStackIndex]; --opStackIndex;

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_C00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"!<"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] <= opStack[opStackIndex]; --opStackIndex;

    //"AND"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "IF")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF7A873D5E0;

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "then"-part of IF-operator)
    opTemp = 1;
LABEL__AFTER_THEN_00007FF7A873D5E0:

    //"ELSE" (part of "ELSEIF")
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF7A873F720;

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"!<"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] <= opStack[opStackIndex]; --opStackIndex;

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"_C00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"!<"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] <= opStack[opStackIndex]; --opStackIndex;

    //"AND"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "ELSEIF")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF7A87424D8;

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"}" (after "then"-part of ELSEIF-operator)
    opTemp = 1;
LABEL__AFTER_ELSE_00007FF7A873F720:
LABEL__AFTER_THEN_00007FF7A87424D8:

    //"ELSE"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF7A8744618;

    //"_C00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "ELSE")
LABEL__AFTER_ELSE_00007FF7A8744618:

    //null statement (non-context)

    //"_Y00"
    opStack[++opStackIndex] = opTemp = data[0x00000010];

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"IF"

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"=="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex]; --opStackIndex;

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_C00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"=="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex]; --opStackIndex;

    //"AND"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex]; --opStackIndex;

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"_C00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"=="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex]; --opStackIndex;

    //"AND"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "IF")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF7A874C2C8;

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "then"-part of IF-operator)
    opTemp = 1;
LABEL__AFTER_THEN_00007FF7A874C2C8:

    //"ELSE"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF7A874DFE0;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "ELSE")
LABEL__AFTER_ELSE_00007FF7A874DFE0:

    //"IF"

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"!<"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] <= opStack[opStackIndex]; --opStackIndex;

    //"NOT"
    opTemp = opStack[opStackIndex] = !opStack[opStackIndex];

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"!<"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] <= opStack[opStackIndex]; --opStackIndex;

    //"NOT"
    opTemp = opStack[opStackIndex] = !opStack[opStackIndex];

    //"OR"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] || opStack[opStackIndex]; --opStackIndex;

    //"_C00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"!<"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] <= opStack[opStackIndex]; --opStackIndex;

    //"NOT"
    opTemp = opStack[opStackIndex] = !opStack[opStackIndex];

    //"OR"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] || opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "IF")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF7A87547C8;

    //"-1"
    opStack[++opStackIndex] = opTemp = 0xFFFFFFFF;

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "then"-part of IF-operator)
    opTemp = 1;
LABEL__AFTER_THEN_00007FF7A87547C8:

    //"ELSE"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF7A87564E0;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "ELSE")
LABEL__AFTER_ELSE_00007FF7A87564E0:

    //"IF"

    //"_A00"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_B00"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"_C00"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"ADD"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"!<"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] <= opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "IF")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF7A875A760;

    //"10"
    opStack[++opStackIndex] = opTemp = 0x0000000A;

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "then"-part of IF-operator)
    opTemp = 1;
LABEL__AFTER_THEN_00007FF7A875A760:

    //"ELSE"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF7A875C478;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"PRINT"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "ELSE")
LABEL__AFTER_ELSE_00007FF7A875C478:

    return 0;
}