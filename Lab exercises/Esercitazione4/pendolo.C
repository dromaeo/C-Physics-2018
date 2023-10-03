/*
  La comprensione di questa macro diventera' piu' chiara nelle prossime
  lezioni. Per il momento limitatevi ad inserire i valori corretti di m, q e
  del nome del file di input, e ad eseguirla con il comando (da terminale)

  root pendolo.C

  (poi, per uscire da root digitare ".q")
 */
{
   double m = 4.049;
   double q = -0.006;
   ifstream file("pendolo.dat");

   
   TGraphErrors* g = new TGraphErrors();
   
   while(file.good()) {
      double x, y, ex, ey;
      file >> x >> y >> ex >> ey;
      if(!file.good())
	 break;
      g->SetPoint(g->GetN(), x, y);
      g->SetPointError(g->GetN() - 1, ex, ey);
   }
   file.close();
   
   g->Draw("ap");

   TF1* f = new TF1("f", "pol1", 0, 0.5);
   f->SetParameter(0, q);
   f->SetParameter(1, m);
   f->DrawCopy("same");
}
