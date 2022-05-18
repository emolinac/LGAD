// Scrip that reads a folder containing oscilloscope output (Time, Amplitude)
// and turns it into a TNtuple

// Put this script inside the data folder and execute from there
void MACRO_DataToTuple(){
  gSystem->Exec("ls -1 > list_of_files.txt");

  std::ifstream file_list("list_of_files.txt");
  std::string file_name;

  TNtuple* ntuple_data = new TNtuple("ntuple_data","","time:ampl"); //check constructor

  while(std::getline(file_list,file_name)){
    std::string out_name       = file_name+".root";
    const char* out_name_valid = out_name.c_str();
    TFile* f = new TFile(out_name_valid,"RECREATE"); // Ojo con esta parte!
    gROOT->cd();
      
    ntuple_data->ReadFile(file_name.c_str());

    f->cd();
    ntuple_data->Write();
    
    delete f;
    ntuple_data->Reset(); //o algo asi
    if(ntuple_data->GetEntries()!=0){
      std::cout<<"Tuple didnt cleaned!"<<std::endl;
    }
  }

  gSystem->Exec("rm list_of_files.txt");

  gSystem->Exec("hadd OutName.root *.root");

  gSystem->Exec("mv OutName.root /home/lgad/Documents/LGAD/DATA_NTUPLES");

  gSystem->Exec("rm *.root");
}
