
{
  ifstream ifile;
  ifile.open("termistore.dat");
  double T, R, eT, eR;
  TGraphErrors gr1;
  
  while (ifile >> T >> R >> eT >> eR){
    if (! ifile.good()){
      cerr << "Errore nella lettura del file" << endl;
      break;
    }
    
    gr1.SetPoint(gr1.GetN(), T+273, R);
    gr1.SetPointError (gr1.GetN()-1, eT, eR);
  }
  ifile.close();
  
  gr1.SetMarkerStyle(21);
  gr1.SetMarkerColor(kBlue);
  gr1.Draw("AP");
  
  TF1 f("f", "[0]*exp([1]/x)", 0, 1);
  f.SetParameter(0, 0.2);
  f.SetParameter(1, 0.2);
  
  gr1.Fit("f");
  gr1.SetLineColor(kBlue);

  
  double f1_0= f.GetParameter(0);
  double f1_1= f.GetParameter(1);
  f.GetParError(0);
  f.GetParError(1);



  double X2= f.GetChisquare();
  cout << endl;
  cout << "Il chi quadro vale X2= " << X2 << endl;
  double nlib= f.GetNDF();
  cout << "Il numero di gradi di liberta' e` N= " << nlib << endl;
  double pX2= f.GetProb();
  cout << "La probabilita' del chi quadro vale " << pX2 << " ( " << pX2*100 << "%)" << endl;
}
