#include "gmock/gmock.h"
#include "device_driver.h"

using namespace testing;

class FlashMock : public FlashMemoryDevice {
public:
	MOCK_METHOD(unsigned char, read, (long address), (override) );
	MOCK_METHOD(void, write, (long address, unsigned char data), (override) );
};


TEST(DeviceDriver, ReadFiveTimesSameReturn) {
	FlashMock mock;
	EXPECT_CALL(mock, read((long)0xB))
		.Times(5)
		.WillRepeatedly(Return(0xB));

	DeviceDriver driver{ &mock };
	int data = driver.read((long)0xB);
	EXPECT_EQ(data, 0xB);

	//EXPECT_THROW({ unsigned char data = driver.read(0xFF); }, ReadFailException);

}


TEST(DeviceDriver, ReadFiveTimesException) {
	FlashMock mock;

	EXPECT_CALL(mock, read((long)0xB))
		.Times(5)
		.WillOnce(Return(0xA))
		.WillOnce(Return(0xA))
		.WillOnce(Return(0xA))
		.WillOnce(Return(0xA))
		.WillOnce(Return(0xB));

	DeviceDriver driver{ &mock };
	EXPECT_THROW(driver.read((long)0xB), std::exception);
}

TEST(DeviceDriverWrite, ReadBeforeWrite) {
	NiceMock<FlashMock> mock;

	EXPECT_CALL(mock, read((long)0xB))
		.Times(1)
		.WillOnce(Return(0xFF));

	DeviceDriver driver{ &mock };

	driver.write((long)0xB, 7);
}

TEST(DeviceDriverWrite, ReadBeforeWriteException) {
	NiceMock<FlashMock> mock;

	EXPECT_CALL(mock, read((long)0xB))
		.Times(1)
		.WillOnce(Return(0xB));

	DeviceDriver driver{ &mock };
	EXPECT_THROW(driver.write((long)0xB, 7), std::exception);
}
int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}