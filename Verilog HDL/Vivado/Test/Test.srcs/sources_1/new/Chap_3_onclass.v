`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/05/2026 08:22:32 AM
// Design Name: 
// Module Name: Chap_3_onclass
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


module adder4b(sum,cout,a,b,cin);
    input [3:0]a;
    input [3:0]b;
    input cin;
    output [3:0]sum;
    output cout;
    
    assign {cout, sum} = a + b + cin;
endmodule

module Comp4b(a_gt_b, a_eq_b, a_lt_b, a, b);
    input [3:0] a,b;
    output a_gt_b, a_eq_b, a_lt_b;
    
    assign a_gt_b = (a > b) ? 1:0;
    assign a_eq_b = (a == b)? 1:0;
    assign a_lt_b = (a < b)? 1:0;
endmodule

module mod10_counter(
    input clk,
    input rst,
    output reg [3:0] count
);

always @(posedge clk) 
    begin
        if(rst)
            count <= 0;
        else if(count == 9)
            count <= 0;
        else
            count <= count + 1;
    end
endmodule

module counter(
    input clk,
    input reset,
    input mode,
    output reg [3:0]count,
    output RCO
);
    assign RCO = (count == 4'b0000);
    always @(posedge clk) 
    begin
        if(!reset)
            count <= 0;
        else begin
            if(mode == 1'b0)
                count <= count + 1;
            else 
                count <= count - 1;
        end
    end
endmodule