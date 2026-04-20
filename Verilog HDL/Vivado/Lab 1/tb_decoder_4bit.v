`timescale 1ns/1ps

module tb_comparator_4bit;

reg [3:0] A, B;
wire A_gt_B, A_lt_B, A_eq_B;

comparator_4bit uut (
    .A(A),
    .B(B),
    .A_gt_B(A_gt_B),
    .A_lt_B(A_lt_B),
    .A_eq_B(A_eq_B)
);

integer i, j;

initial begin
    $display("A    B    | GT LT EQ");

    for (i = 0; i < 16; i = i + 1) begin
        for (j = 0; j < 16; j = j + 1) begin
            A = i;
            B = j;
            #10;
            $display("%4b %4b |  %b  %b  %b",
                     A, B, A_gt_B, A_lt_B, A_eq_B);
        end
    end

    $stop;
end
endmodule