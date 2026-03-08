`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/03/2026 10:47:46 AM
// Design Name: 
// Module Name: test_tb
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


module test_tb();
    wire D,E;
    reg A,B,C;
    Test t1(A,B,C,D,E);
    
    initial begin 
       $dumpfile("test_tb.vcd");
       $dumpvars;
    end
    initial
        begin
            A=1'b0; B=1'b0; C=1'b0;
            #100 A =1'b1; B=1'b1;C=1'b1;
        end
    
    initial #200 $finish;
endmodule