#include "GaleShapley.h"

int main(const int argc, const char* argv[]) {
  printf("*** Size 100 ***\n");
  GaleShapley(Graph("data_size100.csv"));
  printf("\n*** Size 200 ***\n");
  GaleShapley(Graph("data_size200.csv"));
  printf("\n*** Size 500 ***\n");
  GaleShapley(Graph("data_size500.csv"));
  printf("\n*** Size 1,000 ***\n");
  GaleShapley(Graph("data_size1000.csv"));
  printf("\n*** Size 2,000 ***\n");
  GaleShapley(Graph("data_size2000.csv"));
  printf("\n*** Size 5,000 ***\n");
  GaleShapley(Graph("data_size5000.csv"));
  printf("\n*** Size 10,000 ***\n");
  GaleShapley(Graph("data_size10000.csv"));
  printf("\n*** Size 25,000 ***\n");
  GaleShapley(Graph("data_size25000.csv"));
  printf("\n*** JA ***\n");
  GaleShapley(Graph("data_JA.csv"));
  printf("\n*** UT Austin ***\n");
  GaleShapley(Graph("data_UTAustin.csv"));
  printf("\n*** WOOLF ***\n");
  GaleShapley(Graph("data_WOOLF.csv"));
  printf("\n*** Twenty ***\n");
  GaleShapley(Graph("data_twenty.csv"));
  printf("\n*** Fourteen - Uniform Rankings ***\n");
  GaleShapley(Graph("data_fourteen_uniform.csv"));
  printf("\n*** Fourteen - Decreasing Ranks ***\n");
  GaleShapley(Graph("data_fourteen_decreasing.csv"));
  printf("\n*** Fourteen - Uniform with Standout with Female Preferences Better (when used alone) ***\n");
  GaleShapley(Graph("data_fourteen_standout_women.csv"));
  printf("\n*** Fourteen - Uniform with Standout with Male Preferences Better (when used alone) ***\n");
  GaleShapley(Graph("data_fourteen_standout_men.csv"));
}
