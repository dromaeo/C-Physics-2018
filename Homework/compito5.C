{
  cout << "Inserire la funzione:" << endl;
  string fstr;
  cin >> fstr;
  TF2 f("f", fstr.c_str());
  double x, y, dx, dy;
  cout << "Inserire il valore di x e il suo errore:" << endl;
  cin >> x >> dx;
  cout << "Inserire il valore di y e il suo errore:" << endl;
  cin >> y >> dy;
  
  double q= f.Eval (x,y);
  
  double f1= f.Eval(x+dx,y);
  double f2= f.Eval(x-dx,y);
  double dfx= (abs(f1-f2))/2;
  
  double f3= f.Eval(x,y+dy);
  double f4= f.Eval(x,y-dy);
  double dfy= (abs(f3-f4))/2;

  double dq= dfx+dfy;

  cout << "Il risultato è q = " << q << " ± " << dq << endl;
}
