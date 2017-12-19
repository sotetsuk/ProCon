/**
 * Created by sotetsuk on 2015/12/27.
 */
object B {
  def main(args: Array[String]) {
    var m = readDouble()
    m = m / 1000
    if (m < 0.1) {
      m = 0
    } else if (0.1 <= m && m <= 5) {
      m = m * 10
    } else if (6 <= m && m <= 30) {
      m = m + 50
    } else if (35 <= m && m <= 70) {
      m = (m - 30) / 5 + 80
    } else if (m >= 70) {
      m = 89
    }
    println("%02d".format(m.asInstanceOf[Int]))
  }
}
