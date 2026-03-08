`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/04/2026 06:32:49 PM
// Design Name: 
// Module Name: Chap2_ex1_tb
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


module Chap2_ex1_tb();
    reg [2:0]a;
    reg [2:0]b;
    wire a_lt_b;
    wire a_eq_b;
    wire a_gt_b;
    
    bit_comparator test(
        .a(a),
        .b(b),
        .a_lt_b(a_lt_b),
        .a_eq_b(a_eq_b),
        .a_gt_b(a_gt_b)
    );
    
    initial
        begin
            #0 a=3'b000; b=3'b000;
            #20 a=3'b101; b=3'b101;
            #40 a=3'b111; b=3'b110;
            #60 a=3'b100; b=3'b110;
            #80 a=3'b011; b=3'b100;
            #100 $finish;
        end
endmodule
