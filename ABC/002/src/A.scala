/**
 * Created by sotetsuk on 2015/12/24.
 */
object A {
  def main(args:Array[String]):Unit = {
    val x = readLine.split(" ").map(_.toInt)
    if (x(0) > x(1)) {
      println(x(0))
    } else {
      println(x(1))
    }
  }
}
