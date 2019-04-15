import unittest
from  MaxSubarray import MaxSubArray


class TestMaxSubArrayFunc(unittest.TestCase):

    def test_Empty(self):
        self.assertEqual(0,MaxSubArray([]))

    def test_AB_BH(self):
        self.assertEqual(7,MaxSubArray([7,-4,-6]))


if __name__ == '__main__':
        unittest.main(verbosity=2)
