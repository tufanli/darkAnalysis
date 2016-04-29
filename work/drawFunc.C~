void drawFunc()
{
  Double_t alpha_EM =  7.29735257*pow(10.0,-3.0) ; // fine structure constant                                                                                                        
  Double_t pi0_mass = 0.13497; // Pi0 mass (in GeV)                                                                                                                                  
TF1 *func = new TF1("func",Form("(%f*pow(x,3)))/(96*27*0.093*0.093)*pow((1-pow(%f,2)/pow(x,2)),3)",alpha_EM,pi0_mass),0,0.7);
func->Draw();
}
