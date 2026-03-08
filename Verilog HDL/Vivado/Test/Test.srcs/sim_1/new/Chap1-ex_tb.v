`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/03/2026 08:25:45 PM
// Design Name: 
// Module Name: Chap1-ex_tb
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


module Chap1_ex_tb();
    reg [3:0]in;
    reg sel;
    wire [1:0]out;
    
    top_level module_1(
        .a(in[0]),
        .b(in[1]),
        .c(in[2]),
        .d(in[3]),
        .m(sel),
        .s0(out[0]),
        .s1(out[1])
    );
    
    initial
        begin
                in[0] = 1'b0; in[1] = 1'b0; in[2] = 1'b0; in[3] = 1'b0; sel = 1'b0;
            #10 in[0] = 1'b0; in[1] = 1'b0; in[2] = 1'b0; in[3] = 1'b0; sel = 1'b0;
            #20 in[0] = 1'b0; in[1] = 1'b0; in[2] = 1'b0; in[3] = 1'b0; sel = 1'b0;
            #30 in[0] = 1'b0; in[1] = 1'b0; in[2] = 1'b0; in[3] = 1'b0; sel = 1'b0;
            #40 in[0] = 1'b0; in[1] = 1'b0; in[2] = 1'b0; in[3] = 1'b0; sel = 1'b0;
            #50 in[0] = 1'b0; in[1] = 1'b0; in[2] = 1'b0; in[3] = 1'b0; sel = 1'b0;
            #60 in[0] = 1'b0; in[1] = 1'b0; in[2] = 1'b0; in[3] = 1'b0; sel = 1'b0;
            #70 in[0] = 1'b0; in[1] = 1'b0; in[2] = 1'b0; in[3] = 1'b0; sel = 1'b0;
            #80 in[0] = 1'b0; in[1] = 1'b0; in[2] = 1'b0; in[3] = 1'b0; sel = 1'b0;
            
        end
endmodule
