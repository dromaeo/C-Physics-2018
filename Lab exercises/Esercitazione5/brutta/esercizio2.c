{
  TGraphErrors gr1("kater.dat");
  gr.Draw("Ap");
  TF1 f("f", "[0]*x^2+[1]*x+[2]" 0, 1));
f.SetParameter(1, 9.81);
f.SetParameter(2, 4*(3.14^2));
gr1.Fit("f");


  TGraphErrors gr2("kater.dat");
  gr.Draw("p");
  TF1 g("g", "[0]*x^2+[1]*x+[2]" 0, 1));
g.SetParameter(1, 9.81);
g.SetParameter(2, 4*(3.14^2));
gr2.Fit("g");


  TF1 zer("z", "[0]*x^2+[1]*x+[2]" 0, 1));
z.SetParameter(1, 9.81);
z.SetParameter(2, 4*(3.14^2));

}


QUESTIONS
TF (  0,1???)
SetParameter (1???? )
SetPoint??? e gli altri
Come usare esercizio in cpp????
