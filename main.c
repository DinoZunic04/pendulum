#define g 9.80665
#define dt 0.00001
#define M_PI acos(-1.0)
int main()
{
	double l,m,pocetniUgao;
	for(pocetniUgao=0.0;pocetniUgao<=M_PI-dt;pocetniUgao+=M_PI/180.0*1.0)
	{
		printf("O=%d\n",(int)(pocetniUgao*180.0/M_PI+0.0000000001));
		for(l=1.0;l<4.0;l+=1.0)
		{
			printf("l=%3dm: ",(int)l);
			double t,kteta=pocetniUgao,omega=0.0;
			for(t=0.0;;t+=dt)
			{
				omega-=dt*g/l*sin(kteta);
				if(dt*g/l*sin(kteta)==0.0||(znak(kteta)!=znak(kteta+dt*(omega-dt*g/l*sin(kteta))))) break;
				kteta+=dt*omega;
			}
			t*=4.0;
			printf("%16.10lfs\t",t);
		}
		printf("\n");
	}
	return 0;
}
int znak(double d)
{
	if(d<0.0)	return	0;
	else		return	1;
}
