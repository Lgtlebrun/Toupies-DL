data = load("../../cmake-build-debug/StatsOH.txt");
X = data(:,1);
Y = data(:,2);


figure;
plot(X,Y, "rx", "Markersize", 10)
xlabel("Temps")
ylabel("Paramètre")
;

pause;

