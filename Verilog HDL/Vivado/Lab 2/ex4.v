module rgb_controller (
    input wire [1:0] sw,     
    input wire [3:0] button,  
    output reg [2:0] led4_rgb,
    output reg [2:0] led5_rgb 
);

    reg [2:0] current_color;

    always @(*) begin
        case (sw[0])
            1'b0: begin
                case (button)
                    4'b0001: current_color = 3'b001; // Blue
                    4'b0010: current_color = 3'b010; // Green
                    4'b0100: current_color = 3'b100; // Red
                    4'b1000: current_color = 3'b111; // White
                    default: current_color = 3'b000; // OFF
                endcase
                
                if (sw[1] == 1'b0) begin
                    led4_rgb = current_color; // Right ON
                    led5_rgb = 3'b000;
                end else begin
                    led4_rgb = 3'b000;
                    led5_rgb = current_color; // Left ON
                end
            end

            1'b1: begin
                if (sw[1] == 1'b0) begin
                    case (button)
                        4'b0001: current_color = 3'b001; // Blue
                        4'b0010: current_color = 3'b010; // Green
                        4'b0100: current_color = 3'b100; // Red
                        4'b1000: current_color = 3'b111; // White
                        4'b0000: current_color = 3'b000; // OFF
                        default: current_color = 3'b011; // Cyan (Blue & Green)
                    endcase     
                end 
                else begin 
                    case (button)
                        4'b0001: current_color = 3'b011; // Cyan (Blue & Green)
                        4'b0010: current_color = 3'b110; // Yellow (Green & Red)
                        4'b0100: current_color = 3'b101; // Purple (Red & Blue)
                        4'b1000: current_color = 3'b111; // White
                        default: current_color = 3'b000; // OFF
                    endcase
                end
                
                led4_rgb = current_color;
                led5_rgb = current_color;
            end
        endcase
    end

endmodule