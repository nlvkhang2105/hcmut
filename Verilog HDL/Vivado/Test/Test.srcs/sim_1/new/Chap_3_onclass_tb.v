`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/05/2026 08:29:22 AM
// Design Name: 
// Module Name: Chap_3_onclass_tb
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


module adder4b_tb();
    reg [9:0]stim;
    wire [3:0]S;
    wire C4;
    
    adder4b_tb a1(S,C4,stim[8:5],stim[4:1],stim[0]);
    initial $monitor("%t: %b %h %h %h %b", $time, C4, S, stim[8:5], stim[4:1], stim[0]);
    initial
        begin 
            for(stim = 0; stim < 512; stim = stim + 1) #10;
            #10 $finish;
        end
endmodule

module comp4b_tb();
    reg [4:0] a,b;
    wire a_gt,a_eq,a_lt;
    
    Comp4b uut(
        .a(a),
        .b(b),
        .a_gt_b(a_gt),
        .a_eq_b(a_eq),
        .a_lt_b(a_lt)
    );
    
    initial 
        $monitor("%t: A=%h, B=%h, AgtB=%b, AeqB=%b, AltB=%b", $time, a[3:0], b[3:0], a_gt, a_eq, a_lt); 
    initial
        #2000 $finish;
    initial
        begin
            #5;
            for(a = 0; a < 16; a = a+1)
                begin
                    for(b = 0; b < 16; b = b+1)
                        begin 
                            #5;
                        end
                end
        end
endmodule

module mod10_counter_tb();
    reg clk, rst;
    wire [3:0]count;
    initial begin 
       $dumpfile("dump.vcd");
       $dumpvars;
     end
     
endmodule

module counter_tb();
    reg clk, reset, mode;
    wire [3:0] count;
    wire RCO;
    
    counter uut(
        .clk(clk),
        .reset(reset),
        .mode(mode),
        .count(count),
        .RCO(RCO)
    );
    
    initial 
        begin 
            $dumpfile("counter_tb.vcd");
            $dumpvars;
        end
    initial $monitor("time=%t: reset= %b, mode= %b, count= %b, RCO= %b", $time, reset, mode, count, RCO);
    initial
        begin
            clk = 1'b0;
            forever #10 clk = ~clk;
        end
    initial
        begin
            reset = 1'b0;
            mode = 1'b0;
            #25;
            reset = 1'b1;
            #330;
            mode = 1'b1;
            #660;
            $finish;
        end
endmodule
