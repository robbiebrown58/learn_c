
struct{
  unsigned bf_1 :1;
  unsigned bf_2 :1;
  unsigned bf_3 :1;
  unsigned bf_4 :1;
  unsigned :0; //force alignment to a storage unit boundary
  unsigned bf_5 :1;
  unsigned bf_6 :1;
  unsigned bf_7 :1;
  unsigned bf_8 :1;
}bits;

int main(void){

  //                    4321                          
  bits.bf_1 = 0;  //00000000
  bits.bf_2 = 1;  //00000010
  bits.bf_3 = 1;  //00000110
  bits.bf_4 = 1;  //00001110  
  bits.bf_1 = 1;  //00001111
  bits.bf_2 = 0;  //00001101
  bits.bf_2 = 1;  //00001111

  //                    8765
  bits.bf_5 = 0;  //00000000
  bits.bf_6 = 1;  //00000010
  bits.bf_7 = 1;  //00000110
  bits.bf_8 = 1;  //00001110  
  bits.bf_5 = 1;  //00001111
  bits.bf_7 = 0;  //00001011
  bits.bf_5 = 0;  //00001010
  
}
