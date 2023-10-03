
{
  ifstream ifile;
  ifile.open("kater.dat");
  double x, ex, T1, eT1, T2, eT2;
  TGraphErrors gr1;
  TGraphErrors gr2;
  
  while (ifile >> x >> ex >> T1 >> eT1 >> T2 >> eT2){
    if (! ifile.good()){
      cerr << "Errore nella lettura del file" << endl;
      break;
    }
    
    gr1.SetPoint(gr1.GetN(), x, T1);
    gr1.SetPointError (gr1.GetN()-1, ex, eT1);
    gr2.SetPoint (gr2.GetN(), x, T2);
    gr2.SetPointError (gr2.GetN()-1, ex, eT2);
  }
  ifile.close();
  
  gr1.SetMarkerStyle(21);
  gr1.SetMarkerColor(kBlue);
  gr1.Draw("AP");

  gr2.SetMarkerStyle(23);
  gr2.SetMarkerColor(kRed);
  gr2.Draw("P");
  
  TF1 f("f", "[0]*x^2+[1]*x+[2]", 0, 1);
  f.SetParameter(0, 0.005);
  f.SetParameter(1, 0.02);
  f.SetParameter(2, 0.2);
  
  gr1.Fit("f");
  gr1.SetLineColor(kBlue);
  
  
  TF1 g("g", "[0]*x^2+[1]*x+[2]", 0, 1);
  g.SetParameter(0, 0.005 );
  g.SetParameter(1, 0.02);
  g.SetParameter(2, 0.2);
  
  gr2.Fit("g");
  gr2.SetLineColor(kRed);

  
  double f1_0= f.GetParameter(0);
  double f1_1= f.GetParameter(1);
  double f1_2= f.GetParameter(2);
  f.GetParError(0);
  f.GetParError(1);
  f.GetParError(2);

  double f2_0= g.GetParameter(0);
  double f2_1= g.GetParameter(1);
  double f2_2= g.GetParameter(2);
  g.GetParError(0);
  g.GetParError(1);
  g.GetParError(2);


  double a= f1_0-f2_0;
  double b= f1_1-f2_1;
  double c= f1_2-f2_2;

  double delta= (pow(b,2))-(4*a*c);
  double x1=((-(b)+sqrt(delta))/(2*a));

  cout << "I due periodi si eguagliano in x= " << x1 << endl;

  double eva= f.Eval(x1, f1_1);
  cout << "Il periodo di isocronia e` T= " << eva << endl;


  double grav= 4*pow((M_PI),2)*x1/(pow(eva,2));
  cout << "Il valore di g calcolato e` " << grav << " che convertito in m/s^2 e` un valore accettabile di g= " << grav*0.01 << endl;

}
