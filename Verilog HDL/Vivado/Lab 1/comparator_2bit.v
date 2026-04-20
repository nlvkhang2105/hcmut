`timescale 1ns / 1ps

module comparator_2bit (
    input A1, A0, B1, B0,
    output A_gt_B, A_lt_B, A_eq_B
);

    wire E1, E0;
    assign E1 = ~(A1 ^ B1);
    assign E0 = ~(A0 ^ B0);
    assign A_eq_B = E1 & E0;
    assign A_gt_B = (A1 & ~B1) | (E1 & A0 & ~B0);
    assign A_lt_B = (~A1 & B1) | (E1 & ~A0 & B0);
    
endmodule
