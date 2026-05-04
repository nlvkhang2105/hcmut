`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/04/2026 07:06:18 AM
// Design Name: 
// Module Name: Ex2
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


module Ex2(
    input clk_in,
    input rst,
    output reg led
    );
    parameter LIMIT = 62500000;
    reg [25:0]count;
    always @(posedge clk_in) begin
        if(rst) begin
            count <= 0;
            led <= 0;
        end else begin 
            if(count == LIMIT - 1) begin
                count <= 0;
                led <= ~led;
            end else begin
                count <= count + 1;
            end
        end
    end
endmodule
