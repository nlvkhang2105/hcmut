function conservativeforce
clear all
syms t x k q
k = input('Enter the parameter k, k = ');
q = input('Enter the parameter q, q = ');
m = input('Enter the mass of the particle (kg), m = ');
v0 = input('Enter the initial velocity of the particle (m/s), v0 = ');
delta = input('Enter the time step (s), delta = ');
x0 = input('Enter the initial position of the particle, x0 = ');
n = input('Enter the number of steps, n = ');
X = zeros(n+1, 1); V = zeros(n+1, 1); a = zeros(n+1, 1);
U = zeros(n+1, 1); K = zeros(n+1, 1); T = zeros(n+1, 1);
disp('Choosing the potential energy reference position at x = 0');
F = k*x - 4*q*x^3;
V(1) = v0; X(1) = x0; T(1) = 0;
a(1) = double(subs(F, x, X(1)) / m);
U(1) = -double(int(F, x, 0, X(1)));
K(1) = (1/2) * m * V(1)^2;
for i = 1:n
T(i + 1) = T(i) + delta;
X(i + 1) = (1/2) * a(i) * delta^2 + V(i) * delta + X(i);
V(i + 1) = V(i) + a(i) * delta;
a(i + 1) = double(subs(F, x, X(i + 1)) / m);
U(i + 1) = -double(int(F, x, 0, X(i + 1)));
K(i + 1) = (1/2) * m * V(i + 1)^2;
end
hold on
grid on
plot(T, U, 'b')
plot(T, K, 'r')
for j = 1:(n + 1)
disp(['- Potential energy at time t = ', num2str(T(j)), ' is: U= ', num2str(U(j)), ' J']);
disp(['- Kinetic energy at time t = ', num2str(T(j)), ' is: K= ', num2str(K(j)), ' J']);
fprintf('\n');
% Add labels on the plot with Times New Roman font
text(T(j), U(j), sprintf(' %g', j), 'FontName', 'Times New Roman');
text(T(j), K(j), sprintf(' %g', j), 'FontName', 'Times New Roman');
end
xlabel('Time (s)', 'FontName', 'Times New Roman');
ylabel('Energy (J)', 'FontName', 'Times New Roman');
title('Kinetic and Potential Energy of a Particle Moving Under a Force Field', 'FontName', 'Times New Roman');
fprintf('\n');
disp('Note: The numbers 1, 2, .... on the graph represent the state of the particle at each time step.');
end