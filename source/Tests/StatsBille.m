data = load("../../cmake-build-debug/StatsBille.txt");
X = data(:,1);
Y = data(:,2);


figure;
plot(X,Y, "rx", "Markersize", 10)
xlabel("Param�tre x")
ylabel("Param�tre y")
;

pause;
