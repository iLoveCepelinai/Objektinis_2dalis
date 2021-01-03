#include "pch.h"


TEST(ZMOGUS_TEST, ZMOGUS_YRA_VIRTUALUS) {
	Zmogus zmogeliukas("vardas","pavarde");
	EXPECT_EQ(0, zmogeliukas.getVardas());
	EXPECT_EQ(0, zmogeliukas.getPavard());
}

TEST(STUDENTAS_TEST, STUDENTAS_VEIKIA) {
	Studentas studenciokas("Jonas", "Kavaliauskas", { 4,6 }, 4);
	EXPECT_EQ("Jonas", studenciokas.getVardas());
	EXPECT_EQ("Kavaliauskas", studenciokas.getPavard());
	studenciokas.galutinisVid();
	EXPECT_EQ(4.4, studenciokas.getGal());
	EXPECT_TRUE(studenciokas.gavoSkola());
}

TEST(STUDENTAS_STRUCT_TEST, STUDENTO_NUMATYTAS_0) {
	studentas studentelis;
	EXPECT_EQ(0, studentelis.galut);//turi google test sakyti kad klaida
}

int main(int argc, char* argv[]) {
	testing::initGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}