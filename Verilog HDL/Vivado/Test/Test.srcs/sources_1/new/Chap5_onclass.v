`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/16/2026 08:23:44 AM
// Design Name: 
// Module Name: Chap5_onclass
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


module adder4b_behav(Sum,Cout,A,B,Cin);
    input [3:0]A,B;
    input Cin;
    output reg [3:0]Sum;
    output reg Cout;
    always @(A,B,Cin)
        {Cout,Sum} = A + B + Cin;
endmodule

module dff(D,clk,Q,Qbar);
    input D,clk;
    output reg Q,Qbar;
    always @(posedge clk) begin
        Q <= D;
        Qbar <= ~D;
    end
endmodule

module counter4bLoadAndRotate(
    input clk,
    input rst,
    input [3:0]din,
    input load,
    output reg [3:0]counter
    );
    always @(posedge clk)
        begin
            
        end      
endmodule

