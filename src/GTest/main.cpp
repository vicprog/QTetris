#include "Stdafx.h"
//#include <QCoreApplication>

int main(int argc, char** argv)
{
  //::testing::GTEST_FLAG(throw_on_failure) = true;
  ::testing::InitGoogleMock(&argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
//  QCoreApplication a(argc, argv); // For codepage QString
//  a.setApplicationName("Test QЕуекшы");
//  a.setOrganizationName("House");
  return RUN_ALL_TESTS();
}
