

void setupRiddles() {
  // Define All Riddles here

  //const String r1[2] = {"riddle a", "answer a"};
  //const String r2[2] = {"riddle b", "answer b"};

  //const int riddles[NUM_RIDDLES][2] = {r1, r2};
}

void shuffleRiddles() {
  //int list[] = {0, 1, 0, 0, 1, 0, 1, 1, 0};

  for (int a = 0; a < NUM_RIDDLES; a++)
  {
    int r = random(a, NUM_RIDDLES - 1);
    String temp[2] = riddles[a];
    riddles[a][0] = riddles[r][0];
    riddles[a][1] = riddles[r][1];
    riddles[r][0] = temp[0];
    riddles[r][1] = temp[1];
  }
}


