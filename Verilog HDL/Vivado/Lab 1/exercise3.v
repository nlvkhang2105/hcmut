//a
module half_adder (output sum0, carry, input a0, b0);
    
    xor gate0 (sum0, a0, b0);
    and gate1 (carry, a0, b0);

endmodule

//b
module full_adder (output sum, c_out, input a, b, c_in);
    
    wire s1, c1, c2;

    half_adder half1 (s1, c1, a, b);
    half_adder half2 (sum, c2, s1, c_in);

    or gate_or (c_out, c1, c2);

endmodule

//testbench_b
`timescale 1ns/ 1ns

module b_test;

	reg a, b, c_in;
	wire sum, c_out;

	full_adder FA (.a(a), .b(b), .c_in(c_in), .sum(sum), .c_out(c_out));

	initial begin 
		$display("\nFull Adder");
		$monitor("a = %b b = %b c_in=%b -> sum = %b c_out = %b", a, b, c_in, sum, c_out);

		a = 0; b = 0; c_in = 0; #10;
		a = 0; b = 0; c_in = 1; #10;
		a = 0; b = 1; c_in = 0; #10;
		a = 0; b = 1; c_in = 1; #10;
		a = 1; b = 0; c_in = 0; #10;
		a = 1; b = 0; c_in = 1; #10;
		a = 1; b = 1; c_in = 0; #10;
		a = 1; b = 1; c_in = 1; #10;
	end
endmodule

//c
module four_bit_ripplecarry_adder (output s0, s1, s2, s3, c4, input a0, a1, a2, a3, b0, b1, b2, b3, c0);

	wire c1, c2, c3;

	full_adder FA1 (s0, c1, a0, b0, c0);
	full_adder FA2 (s1, c2, a1, b1, c1);
	full_adder FA3 (s2, c3, a2, b2, c2);
	full_adder FA4 (s3, c4, a3, b3, c3);

endmodule

//testbench_c
`timescale 1ns/1ns

module c_test;
	reg [3:0] A, B;
	reg c0;
	wire [3:0] S;
	wire c4;
	integer i;
	four_bit_ripplecarry_adder fbRA (
	.s0(S[0]), .s1(S[1]), .s2(S[2]), .s3(S[3]),
        .c4(c4),
        .a0(A[0]), .a1(A[1]), .a2(A[2]), .a3(A[3]),
        .b0(B[0]), .b1(B[1]), .b2(B[2]), .b3(B[3]),
        .c0(c0)
	);

	initial begin
		$display("\n4-bit Ripple Carry Adder");
			for (i = 0; i < 512; i = i + 1) begin
				{A, B, c0} = i;
				#1;
				$display("A=%b B=%b Cin=%b -> S=%b Cout=%b",
          		A, B, c0, S, c4);
			end
		$stop;
	end
endmodule



