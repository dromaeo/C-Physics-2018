{
  TGraphErrors gr("misure_linearizzate_errx.dat");
  gr.Draw("AP");

  TF1 f("f", "[0]+[1]*x", 0, 0.5);
  f.SetParameter(0, 0);
  f.SetParameter(1, 4);

  gr.Fit("f");
}
