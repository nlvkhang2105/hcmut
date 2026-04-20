`timescale 1ns / 1ps

module comparator_4bit (
    input [3:0] A,
    input [3:0] B,
    output A_gt_B,
    output A_lt_B,
    output A_eq_B
);

    wire GH, LH, EH;
    wire GL, LL, EL;
    
    comparator_2bit CMP_H (
        .A1(A[3]), .A0(A[2]),
        .B1(B[3]), .B0(B[2]),
        .A_gt_B(GH),
        .A_lt_B(LH),
        .A_eq_B(EH)
    );
    
    comparator_2bit CMP_L (
        .A1(A[1]), .A0(A[0]),
        .B1(B[1]), .B0(B[0]),
        .A_gt_B(GL),
        .A_lt_B(LL),
        .A_eq_B(EL)
    );
    
    assign A_gt_B = GH | (EH & GL);
    assign A_lt_B = LH | (EH & LL);
    assign A_eq_B = EH & EL;
    
endmodule
