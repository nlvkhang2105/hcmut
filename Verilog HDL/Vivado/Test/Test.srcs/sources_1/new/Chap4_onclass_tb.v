`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/12/2026 09:06:09 AM
// Design Name: 
// Module Name: Chap4_onclass_tb
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


module mac_tb();
    wire [3:0] A,B;
    wire [7:0] C;
    reg [7:0]Z;
    reg Ovflw;
    
    mac uut(
        .A(A),
        .B(B),
        .C(C),
        .Z(Z)
        );
endmodule
