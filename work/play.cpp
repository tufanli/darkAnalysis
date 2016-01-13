void play()
{
  TSystemDirectory dir("./", "./");
  TList *files = dir.GetListOfFiles();
  if (files)
    {
      TSystemFile *file;
      TString fname;
      TIter next(files);
      while ((file=(TSystemFile*)next())) 
	{
	  fname = file->GetName();

	  fname.ReplaceAll("boone","");
	  fname.ReplaceAll("_","000");
	  fname.ReplaceAll(".root","");

	  cout << "atoi = " << fname.Atoi()<< endl;
	  cout << fname.Data()<< endl;
	  int iposcmt = fname.Index("//");
	  if(iposcmt!=kNPOS) fname.Remove(iposcmt, fname.Length()-iposcmt);
	  
	  // Check number of columns.
	  TObjArray *tokens = fname.Tokenize("_");
	  int ntokens = tokens->GetEntries();

	  cout << fname << ", " << ntokens << endl;
	}
    }
}
