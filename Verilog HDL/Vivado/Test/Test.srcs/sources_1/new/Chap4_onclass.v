`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/12/2026 08:25:35 AM
// Design Name: 
// Module Name: Chap4_onclass
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


module arith(a,b,op,result);
    input [3:0] a, b;
    input [2:0]op;
    output reg [7:0]result;
    
    
endmodule

module mac(output [7:0]Z, output Ovflw, input[3:0] A,B, input [7:0]C);
    wire [8:0]P;
    assign P = A*B + C;
    assign Z = P[7:0];
    assign Ovflw = P[8]; 
endmodule

module rps(win,player,p0guess,p1guess);
    input [1:0]p0guess;
    input [1:0]p1guess;
    output win;
    output player;
    wire p0win;
    wire p1win;
    assign p0win = ((p0guess == 2'b00 && p1guess == 2'b01) || (p0guess == 2'b00 && p1guess == 2'b10) || (p0guess == 2'b01 && p1guess == 2'b10))? 1'b1 : 1'b0;
    assign win = p1win | p0win;
endmodule