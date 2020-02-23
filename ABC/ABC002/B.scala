/**
 * Created by sotetsuk on 2015/12/28.
 */
object B {
  def main(args: Array[String]) {
    val w = readLine()
    println(w.filter(_ != 'a').filter(_ != 'i').filter(_ != 'u').filter(_ != 'e').filter(_ != 'o'))
  }
}
