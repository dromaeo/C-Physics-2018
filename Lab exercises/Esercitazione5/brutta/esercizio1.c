{
  TGraphErrors gr("misure_linearizzate.dat");
  gr.Draw("A*");
  TF1 f("f", "[0]*x^2-[1]*y" 0, 1));
f.SetParameter(1, 9.81);
f.SetParameter(2, 4*(3.14^2));
g.Fit("f");
}
