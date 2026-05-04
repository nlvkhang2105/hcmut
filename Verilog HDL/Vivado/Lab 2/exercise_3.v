`timescale 1ns / 1ps
module bin2led7(
    input enable,
    input [3:0] bin_in,
    output [3:0] led_out
);

    assign led_out = enable ? bin_in: 4'b0000;
endmodule
