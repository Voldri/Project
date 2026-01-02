.686
.model flat, stdcall
option casemap : none

GetStdHandle proto STDCALL, nStdHandle : DWORD
ExitProcess proto STDCALL, uExitCode : DWORD
;MessageBoxA PROTO hwnd : DWORD, lpText : DWORD, lpCaption : DWORD, uType : DWORD
ReadConsoleA proto STDCALL, hConsoleInput : DWORD, lpBuffer : DWORD, nNumberOfCharsToRead : DWORD, lpNumberOfCharsRead : DWORD, lpReserved : DWORD
WriteConsoleA proto STDCALL, hConsoleOutput : DWORD, lpBuffert : DWORD, nNumberOfCharsToWrite : DWORD, lpNumberOfCharsWritten : DWORD, lpReserved : DWORD
wsprintfA PROTO C : VARARG

GetConsoleMode PROTO STDCALL, hConsoleHandle:DWORD, lpMode : DWORD

SetConsoleMode PROTO STDCALL, hConsoleHandle:DWORD, dwMode : DWORD

ENABLE_LINE_INPUT EQU 0002h
ENABLE_ECHO_INPUT EQU 0004h

.data
    data_start db 32768 dup (0)
    ;title_msg db "Output:", 0
    valueTemp_msg db 256 dup(0)
    valueTemp_fmt db "%d", 10, 13, 0
    ;NumberOfCharsWritten dd 0
    hConsoleInput dd 0
    hConsoleOutput dd 0
    buffer db 128 dup(0)
    readOutCount dd ?

.code
start:

    db 0E8h, 00h, 00h, 00h, 00h; call NexInstruction
;NexInstruction:
    pop esi
    sub esi, 5
    mov edi, esi
    add edi, 000004000h
    mov ecx, edi
    add ecx, 24576
    jmp initConsole
    putProc PROC
        push eax
        push offset valueTemp_fmt
        push offset valueTemp_msg
        call wsprintfA
        add esp, 12

        ;push 40h
        ;push offset title_msg
        ;push offset valueTemp_msg;
        ;push 0
        ;call MessageBoxA

        push 0
        push 0; offset NumberOfCharsWritten
        push eax; NumberOfCharsToWrite
        push offset valueTemp_msg
        push hConsoleOutput
        call WriteConsoleA

        ret
    putProc ENDP


    getProc PROC
        push ebp
        mov ebp, esp

        push 0
        push offset readOutCount
        push 15
        push offset buffer + 1
        push hConsoleInput
        call ReadConsoleA

        lea esi, offset buffer
        add esi, readOutCount
        sub esi, 2
        call string_to_int

        mov esp, ebp
        pop ebp
        ret
    getProc ENDP

    string_to_int PROC
    ;  input: ESI - string
    ; output: EAX - value
        xor eax, eax
        mov ebx, 1
        xor ecx, ecx

convert_loop :
        movzx ecx, byte ptr[esi]
        cmp ecx, '+'
        jz done
        cmp ecx, '-'
        jz neg_and_done
        test ecx, ecx
        jz done
        sub ecx, '0'
        imul ecx, ebx
        add eax, ecx
        imul ebx, ebx, 10
        dec esi
        jmp convert_loop

neg_and_done:
        neg eax
done:
        ret
    string_to_int ENDP

    initConsole:
    push -10
    call GetStdHandle
    mov hConsoleInput, eax
    push -11
    call GetStdHandle
    mov hConsoleOutput, eax
    
    ;push ecx
    ;push ebx
    ;push esi
    ;push edi
    ;push offset mode
    ;push hConsoleInput
    ;call GetConsoleMode
    ;mov ebx, eax
    ;or ebx, ENABLE_LINE_INPUT 
    ;or ebx, ENABLE_ECHO_INPUT
    ;push ebx
    ;push hConsoleInput
    ;call SetConsoleMode
    ;pop edi
    ;pop esi
    ;pop ebx
    ;pop ecx

    ;hw stack save(save esp)
    mov ebp, esp

    ;";"

    ;"4"
    add ecx, 4
    mov eax, 000000004h
    mov dword ptr [ecx], eax

    ;"SCAN"
    mov eax, dword ptr[ecx]
    mov edx, 000000047h
    add edx, esi
    push ecx
    ;push ebx
    push esi
    push edi
    call edx
    pop edi
    pop esi
    ;pop ebx
    pop ecx
    mov ebx, dword ptr[ecx]
    sub ecx, 4
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;";"

    ;"8"
    add ecx, 4
    mov eax, 000000008h
    mov dword ptr [ecx], eax

    ;"SCAN"
    mov eax, dword ptr[ecx]
    mov edx, 000000047h
    add edx, esi
    push ecx
    ;push ebx
    push esi
    push edi
    call edx
    pop edi
    pop esi
    ;pop ebx
    pop ecx
    mov ebx, dword ptr[ecx]
    sub ecx, 4
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;";"

    ;"12"
    add ecx, 4
    mov eax, 00000000Ch
    mov dword ptr [ecx], eax

    ;"SCAN"
    mov eax, dword ptr[ecx]
    mov edx, 000000047h
    add edx, esi
    push ecx
    ;push ebx
    push esi
    push edi
    call edx
    pop edi
    pop esi
    ;pop ebx
    pop ecx
    mov ebx, dword ptr[ecx]
    sub ecx, 4
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;";"

    ;"IF"

    ;"_A00"
    mov eax, edi
    add eax, 000000004h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"_B00"
    mov eax, edi
    add eax, 000000008h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"!<"
    mov eax, dword ptr[ecx]
    sub ecx, 4
    cmp dword ptr[ecx], eax
    setle al
    and eax, 1
    mov dword ptr[ecx], eax

    ;"_A00"
    mov eax, edi
    add eax, 000000004h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"_C00"
    mov eax, edi
    add eax, 00000000Ch
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"!<"
    mov eax, dword ptr[ecx]
    sub ecx, 4
    cmp dword ptr[ecx], eax
    setle al
    and eax, 1
    mov dword ptr[ecx], eax

    ;"AND"
    mov eax, dword ptr[ecx]
    cmp eax, 0
    setne al
    and eax, 1
    sub ecx, 4
    cmp dword ptr[ecx], 0
    setne dl
    and edx, 1
    and eax, edx
    mov dword ptr[ecx], eax

    ;null statement (non-context)

    ;after cond expresion (after "IF")
    cmp eax, 0
    jz LABEL@AFTER_THEN_00007FF7A873D5E0

    ;"_A00"
    mov eax, edi
    add eax, 000000004h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"16"
    add ecx, 4
    mov eax, 000000010h
    mov dword ptr [ecx], eax

    ;"->"
    mov ebx, dword ptr[ecx]
    mov eax, dword ptr[ecx - 4]
    sub ecx, 8
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;";"

    ;";" (after "then"-part of IF-operator)
    mov eax, 1
LABEL@AFTER_THEN_00007FF7A873D5E0:

    ;"ELSE" (part of "ELSEIF")
    cmp eax, 0
    jnz LABEL@AFTER_ELSE_00007FF7A873F720

    ;"_B00"
    mov eax, edi
    add eax, 000000008h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"_A00"
    mov eax, edi
    add eax, 000000004h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"!<"
    mov eax, dword ptr[ecx]
    sub ecx, 4
    cmp dword ptr[ecx], eax
    setle al
    and eax, 1
    mov dword ptr[ecx], eax

    ;"_B00"
    mov eax, edi
    add eax, 000000008h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"_C00"
    mov eax, edi
    add eax, 00000000Ch
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"!<"
    mov eax, dword ptr[ecx]
    sub ecx, 4
    cmp dword ptr[ecx], eax
    setle al
    and eax, 1
    mov dword ptr[ecx], eax

    ;"AND"
    mov eax, dword ptr[ecx]
    cmp eax, 0
    setne al
    and eax, 1
    sub ecx, 4
    cmp dword ptr[ecx], 0
    setne dl
    and edx, 1
    and eax, edx
    mov dword ptr[ecx], eax

    ;null statement (non-context)

    ;after cond expresion (after "ELSEIF")
    cmp eax, 0
    jz LABEL@AFTER_THEN_00007FF7A87424D8

    ;"_B00"
    mov eax, edi
    add eax, 000000008h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"16"
    add ecx, 4
    mov eax, 000000010h
    mov dword ptr [ecx], eax

    ;"->"
    mov ebx, dword ptr[ecx]
    mov eax, dword ptr[ecx - 4]
    sub ecx, 8
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;";"

    ;"}" (after "then"-part of ELSEIF-operator)
    mov eax, 1
LABEL@AFTER_ELSE_00007FF7A873F720:
LABEL@AFTER_THEN_00007FF7A87424D8:

    ;"ELSE"
    cmp eax, 0
    jnz LABEL@AFTER_ELSE_00007FF7A8744618

    ;"_C00"
    mov eax, edi
    add eax, 00000000Ch
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"16"
    add ecx, 4
    mov eax, 000000010h
    mov dword ptr [ecx], eax

    ;"->"
    mov ebx, dword ptr[ecx]
    mov eax, dword ptr[ecx - 4]
    sub ecx, 8
    add ebx, edi
    mov dword ptr [ebx], eax
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;";"

    ;";" (after "ELSE")
LABEL@AFTER_ELSE_00007FF7A8744618:

    ;null statement (non-context)

    ;"_Y00"
    mov eax, edi
    add eax, 000000010h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"PRINT"
    mov eax, dword ptr[ecx]
    mov edx, 00000001Eh
    add edx, esi
    ;push ecx
    ;push ebx
    push esi
    push edi
    call edx
    pop edi
    pop esi
    ;pop ebx
    ;pop ecx
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;";"

    ;"IF"

    ;"_A00"
    mov eax, edi
    add eax, 000000004h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"_B00"
    mov eax, edi
    add eax, 000000008h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"=="
    mov eax, dword ptr[ecx]
    sub ecx, 4
    cmp dword ptr[ecx], eax
    sete al
    and eax, 1
    mov dword ptr[ecx], eax

    ;"_A00"
    mov eax, edi
    add eax, 000000004h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"_C00"
    mov eax, edi
    add eax, 00000000Ch
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"=="
    mov eax, dword ptr[ecx]
    sub ecx, 4
    cmp dword ptr[ecx], eax
    sete al
    and eax, 1
    mov dword ptr[ecx], eax

    ;"AND"
    mov eax, dword ptr[ecx]
    cmp eax, 0
    setne al
    and eax, 1
    sub ecx, 4
    cmp dword ptr[ecx], 0
    setne dl
    and edx, 1
    and eax, edx
    mov dword ptr[ecx], eax

    ;"_B00"
    mov eax, edi
    add eax, 000000008h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"_C00"
    mov eax, edi
    add eax, 00000000Ch
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"=="
    mov eax, dword ptr[ecx]
    sub ecx, 4
    cmp dword ptr[ecx], eax
    sete al
    and eax, 1
    mov dword ptr[ecx], eax

    ;"AND"
    mov eax, dword ptr[ecx]
    cmp eax, 0
    setne al
    and eax, 1
    sub ecx, 4
    cmp dword ptr[ecx], 0
    setne dl
    and edx, 1
    and eax, edx
    mov dword ptr[ecx], eax

    ;null statement (non-context)

    ;after cond expresion (after "IF")
    cmp eax, 0
    jz LABEL@AFTER_THEN_00007FF7A874C2C8

    ;"1"
    add ecx, 4
    mov eax, 000000001h
    mov dword ptr [ecx], eax

    ;"PRINT"
    mov eax, dword ptr[ecx]
    mov edx, 00000001Eh
    add edx, esi
    ;push ecx
    ;push ebx
    push esi
    push edi
    call edx
    pop edi
    pop esi
    ;pop ebx
    ;pop ecx
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;";"

    ;";" (after "then"-part of IF-operator)
    mov eax, 1
LABEL@AFTER_THEN_00007FF7A874C2C8:

    ;"ELSE"
    cmp eax, 0
    jnz LABEL@AFTER_ELSE_00007FF7A874DFE0

    ;"0"
    add ecx, 4
    mov eax, 000000000h
    mov dword ptr [ecx], eax

    ;"PRINT"
    mov eax, dword ptr[ecx]
    mov edx, 00000001Eh
    add edx, esi
    ;push ecx
    ;push ebx
    push esi
    push edi
    call edx
    pop edi
    pop esi
    ;pop ebx
    ;pop ecx
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;";"

    ;";" (after "ELSE")
LABEL@AFTER_ELSE_00007FF7A874DFE0:

    ;"IF"

    ;"_A00"
    mov eax, edi
    add eax, 000000004h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"0"
    add ecx, 4
    mov eax, 000000000h
    mov dword ptr [ecx], eax

    ;"!<"
    mov eax, dword ptr[ecx]
    sub ecx, 4
    cmp dword ptr[ecx], eax
    setle al
    and eax, 1
    mov dword ptr[ecx], eax

    ;"NOT"
    mov eax, dword ptr[ecx]
    cmp eax, 0
    sete al
    and eax, 1
    mov dword ptr[ecx], eax

    ;"_B00"
    mov eax, edi
    add eax, 000000008h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"0"
    add ecx, 4
    mov eax, 000000000h
    mov dword ptr [ecx], eax

    ;"!<"
    mov eax, dword ptr[ecx]
    sub ecx, 4
    cmp dword ptr[ecx], eax
    setle al
    and eax, 1
    mov dword ptr[ecx], eax

    ;"NOT"
    mov eax, dword ptr[ecx]
    cmp eax, 0
    sete al
    and eax, 1
    mov dword ptr[ecx], eax

    ;"OR"
    mov eax, dword ptr[ecx]
    cmp eax, 0
    setne al
    and eax, 1
    sub ecx, 4
    cmp dword ptr[ecx], 0
    setne dl
    and edx, 1
    or eax, edx
    mov dword ptr[ecx], eax

    ;"_C00"
    mov eax, edi
    add eax, 00000000Ch
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"0"
    add ecx, 4
    mov eax, 000000000h
    mov dword ptr [ecx], eax

    ;"!<"
    mov eax, dword ptr[ecx]
    sub ecx, 4
    cmp dword ptr[ecx], eax
    setle al
    and eax, 1
    mov dword ptr[ecx], eax

    ;"NOT"
    mov eax, dword ptr[ecx]
    cmp eax, 0
    sete al
    and eax, 1
    mov dword ptr[ecx], eax

    ;"OR"
    mov eax, dword ptr[ecx]
    cmp eax, 0
    setne al
    and eax, 1
    sub ecx, 4
    cmp dword ptr[ecx], 0
    setne dl
    and edx, 1
    or eax, edx
    mov dword ptr[ecx], eax

    ;null statement (non-context)

    ;after cond expresion (after "IF")
    cmp eax, 0
    jz LABEL@AFTER_THEN_00007FF7A87547C8

    ;"-1"
    add ecx, 4
    mov eax, 0FFFFFFFFh
    mov dword ptr [ecx], eax

    ;"PRINT"
    mov eax, dword ptr[ecx]
    mov edx, 00000001Eh
    add edx, esi
    ;push ecx
    ;push ebx
    push esi
    push edi
    call edx
    pop edi
    pop esi
    ;pop ebx
    ;pop ecx
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;";"

    ;";" (after "then"-part of IF-operator)
    mov eax, 1
LABEL@AFTER_THEN_00007FF7A87547C8:

    ;"ELSE"
    cmp eax, 0
    jnz LABEL@AFTER_ELSE_00007FF7A87564E0

    ;"0"
    add ecx, 4
    mov eax, 000000000h
    mov dword ptr [ecx], eax

    ;"PRINT"
    mov eax, dword ptr[ecx]
    mov edx, 00000001Eh
    add edx, esi
    ;push ecx
    ;push ebx
    push esi
    push edi
    call edx
    pop edi
    pop esi
    ;pop ebx
    ;pop ecx
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;";"

    ;";" (after "ELSE")
LABEL@AFTER_ELSE_00007FF7A87564E0:

    ;"IF"

    ;"_A00"
    mov eax, edi
    add eax, 000000004h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"_B00"
    mov eax, edi
    add eax, 000000008h
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"_C00"
    mov eax, edi
    add eax, 00000000Ch
    mov eax, dword ptr[eax]
    add ecx, 4
    mov dword ptr [ecx], eax

    ;"ADD"
    mov eax, dword ptr[ecx]
    sub ecx, 4
    add dword ptr[ecx], eax
    mov eax, dword ptr[ecx]

    ;"!<"
    mov eax, dword ptr[ecx]
    sub ecx, 4
    cmp dword ptr[ecx], eax
    setle al
    and eax, 1
    mov dword ptr[ecx], eax

    ;null statement (non-context)

    ;after cond expresion (after "IF")
    cmp eax, 0
    jz LABEL@AFTER_THEN_00007FF7A875A760

    ;"10"
    add ecx, 4
    mov eax, 00000000Ah
    mov dword ptr [ecx], eax

    ;"PRINT"
    mov eax, dword ptr[ecx]
    mov edx, 00000001Eh
    add edx, esi
    ;push ecx
    ;push ebx
    push esi
    push edi
    call edx
    pop edi
    pop esi
    ;pop ebx
    ;pop ecx
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;";"

    ;";" (after "then"-part of IF-operator)
    mov eax, 1
LABEL@AFTER_THEN_00007FF7A875A760:

    ;"ELSE"
    cmp eax, 0
    jnz LABEL@AFTER_ELSE_00007FF7A875C478

    ;"0"
    add ecx, 4
    mov eax, 000000000h
    mov dword ptr [ecx], eax

    ;"PRINT"
    mov eax, dword ptr[ecx]
    mov edx, 00000001Eh
    add edx, esi
    ;push ecx
    ;push ebx
    push esi
    push edi
    call edx
    pop edi
    pop esi
    ;pop ebx
    ;pop ecx
    mov ecx, edi ; reset second stack
    add ecx, 24576 ; reset second stack

    ;null statement (non-context)

    ;";"

    ;";" (after "ELSE")
LABEL@AFTER_ELSE_00007FF7A875C478:

    ;hw stack reset(restore esp)
    mov esp, ebp

    xor eax, eax
    ret


end start


