`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/04/2026 07:36:30 AM
// Design Name: 
// Module Name: Ex2_tb
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


module Ex2_tb();
    reg clk_in;
    reg rst;
    wire led;
    Ex2 #(.LIMIT(10)) uut(
        .clk_in(clk_in),
        .led(led),
        .rst(rst)
    );
    initial begin
        clk_in = 0;
        forever #4 clk_in = ~clk_in;
    end

    initial begin
        rst = 1; #20;   // Hold reset
        rst = 0;        
        #400;
        $finish;
    end

    initial $monitor("Time: %0t | Count: %d | LED: %b", $time, uut.count, led);
endmodule
