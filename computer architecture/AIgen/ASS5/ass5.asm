        .ORIG x3000

        JSR READ_NUM
        ST  R1, XVAL

        LD  R1, XVAL
        JSR IS_PRIME
        BRp PRIME_CASE

        LD  R1, XVAL
        JSR PRINT_NUM
        LEA R0, NOT_STR
        TRAP x22
        ADD R1, R2, #0
        JSR PRINT_NUM
        LD  R0, NEWLINE
        TRAP x21
        TRAP x25

PRIME_CASE
        LD  R1, XVAL
        JSR PRINT_NUM
        LEA R0, PRIME_STR
        TRAP x22
        LD  R0, NEWLINE
        TRAP x21
        TRAP x25

READ_NUM
        AND R1, R1, #0
RN_SKIP
        TRAP x20
        LD  R2, NEG_SPACE
        ADD R2, R0, R2
        BRz RN_SKIP
        LD  R2, NEG_NL
        ADD R2, R0, R2
        BRz RN_SKIP
        LD  R2, NEG_CR
        ADD R2, R0, R2
        BRz RN_SKIP
RN_DIG
        LD  R2, NEG_0
        ADD R2, R0, R2
        BRn RN_DONE
        LD  R3, NEG_9
        ADD R3, R0, R3
        BRp RN_DONE

        ADD R3, R1, #0
        ADD R1, R1, R1
        ADD R1, R1, R1
        ADD R1, R1, R1
        ADD R1, R1, R3
        ADD R1, R1, R3
        ADD R1, R1, R2

        TRAP x20
        LD  R2, NEG_SPACE
        ADD R2, R0, R2
        BRz RN_DONE
        LD  R2, NEG_NL
        ADD R2, R0, R2
        BRz RN_DONE
        LD  R2, NEG_CR
        ADD R2, R0, R2
        BRz RN_DONE
        BR  RN_DIG
RN_DONE
        RET

IS_PRIME
        ADD R3, R1, #0
        BRp IP_POS
        AND R0, R0, #0
        AND R2, R2, #0
        ADD R2, R2, #1
        RET
IP_POS
        ADD R3, R1, #-1
        BRp IP_GT1
        AND R0, R0, #0
        AND R2, R2, #0
        ADD R2, R2, #1
        RET
IP_GT1
        ADD R3, R1, #-2
        BRz IP_PRIME
        ADD R3, R1, #-3
        BRz IP_PRIME

        AND R3, R1, #1
        BRp IP_ODD
        AND R0, R0, #0
        AND R2, R2, #0
        ADD R2, R2, #2
        RET

IP_ODD
        AND R3, R3, #0
        ADD R3, R3, #3
IP_DLOOP
        AND R4, R4, #0
        ADD R5, R3, #0
IP_SQ
        BRz IP_SQDONE
        ADD R4, R4, R3
        ADD R5, R5, #-1
        BRp IP_SQ
IP_SQDONE
        NOT R6, R4
        ADD R6, R6, #1
        ADD R6, R1, R6
        BRn IP_PRIME

        ADD R5, R1, #0
IP_MOD
        NOT R6, R3
        ADD R6, R6, #1
        ADD R6, R5, R6
        BRn IP_MODDONE
        ADD R5, R6, #0
        BR  IP_MOD
IP_MODDONE
        ADD R5, R5, #0
        BRz IP_COMP

        ADD R3, R3, #2
        BR  IP_DLOOP

IP_COMP
        AND R0, R0, #0
        ADD R2, R3, #0
        RET

IP_PRIME
        AND R0, R0, #0
        ADD R0, R0, #1
        AND R2, R2, #0
        RET

PRINT_NUM
        ADD R2, R1, #0
        BRp PN_NZ
        LD  R0, CHAR0
        TRAP x21
        RET
PN_NZ
        AND R4, R4, #0
        LEA R5, DIVTAB
        AND R6, R6, #0
        ADD R6, R6, #5
PN_LOOP
        LDR R2, R5, #0
        AND R3, R3, #0
PN_SUB
        NOT R0, R2
        ADD R0, R0, #1
        ADD R0, R1, R0
        BRn PN_DDONE
        ADD R1, R0, #0
        ADD R3, R3, #1
        BR  PN_SUB
PN_DDONE
        ADD R0, R4, #0
        BRp PN_PRT
        ADD R0, R3, #0
        BRz PN_SKIP
PN_PRT
        ADD R4, R4, #1
        LD  R0, CHAR0
        ADD R0, R0, R3
        TRAP x21
PN_SKIP
        ADD R6, R6, #-1
        BRz PN_END
        ADD R5, R5, #1
        BR  PN_LOOP
PN_END
        RET

XVAL    .BLKW 1

DIVTAB  .FILL #10000
        .FILL #1000
        .FILL #100
        .FILL #10
        .FILL #1

PRIME_STR .STRINGZ " is a prime number"
NOT_STR   .STRINGZ " is not a prime number as it is divisible by "

NEWLINE   .FILL x000A
CHAR0     .FILL x0030
NEG_SPACE .FILL xFFE0
NEG_NL    .FILL xFFF6
NEG_CR    .FILL xFFF3
NEG_0     .FILL xFFD0
NEG_9     .FILL xFFC7

        .END