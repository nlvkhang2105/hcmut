`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/03/2026 09:22:16 PM
// Design Name: 
// Module Name: Chap2_ex1
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module bit_comparator(a,b,a_lt_b,a_eq_b,a_gt_b);
    input [2:0]a; 
    input [2:0]b;
    output a_lt_b, a_eq_b, a_gt_b;
    
    assign a_lt_b = (~a[2] & b[2]) | ((a[2] == b[2]) & ~a[1] & b[1]) | ((a[2] == b[2]) & (a[1] == b[1]) & ~a[0] & b[0]);
    assign a_eq_b = (a[2] == b[2]) & (a[1] == b[1]) & (a[0] == b[0]);
    assign a_gt_b = (a[2] & ~b[2]) | ((a[2] == b[2]) & a[1] & ~b[1]) | ((a[1] == b[1]) & (a[0] == b[0]) & a[0] & ~b[0]);
endmodule
