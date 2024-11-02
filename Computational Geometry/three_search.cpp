Pt arr[MXN];
double checky(double x, double y) { //搜半徑
	double cmax = 0;
	for(int i = 0; i < n; i++) {
		cmax = max(cmax,(arr[i].x - x) * (arr[i].x - x) + 
                   (arr[i].y - y) * (arr[i].y - y));
	}// 過程中回傳距離^2 避免不必要的根號運算
	return cmax;
}
double checkx(double x){ //有了x再搜y
    double yl = -1e9, yr = 1e9;
    while(yr - yl > EPS) {
        double ml = (yl+yl+yr) / 3, mr = (yl+yr+yr) / 3;
        if (checky(x, ml) < checky(x, mr))    yr = mr;	
        else                    	          yl = ml;
    }
}
double xl = -1e9, xr = 1e9; //先搜x
while(xr - xl > EPS) {
	double ml = (xl+xl+xr) / 3, mr = (xl+xr+xr) / 3;
	if (checkx(ml) < checkx(mr))    xr = mr;	
	else                    	   xl = ml;
}