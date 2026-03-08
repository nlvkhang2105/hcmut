`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/03/2026 11:21:21 AM
// Design Name: 
// Module Name: Chap1-ex
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


module top_level(a,b,c,d,m,s0,s1);
    input a,b,c,d,m;
    output s0,s1;
    wire [1:0]w;
    
    mux_2_to_1 mux1(
        .in1(a),
        .in2(c),
        .sel(m),
        .out1(w[0])
    );
    mux_2_to_1 mux2(
        .in1(b),
        .in2(d),
        .sel(m),
        .out1(w[1])
    );
    half_adder h_add(
        .in1(w[0]),
        .in2(w[1]),
        .sum(s0),
        .cout(s1)
    );
endmodule

module mux_2_to_1(in1,in2,sel,out1);
    input in1,in2,sel;
    output out1;
    
    assign out1 = sel ? in1:in2;
endmodule

module half_adder(in1,in2,sum,cout);
    input in1,in2;
    output sum,cout;
    
    assign sum = in1 ^ in2;
    assign cout = in1 & in2;
endmodule
