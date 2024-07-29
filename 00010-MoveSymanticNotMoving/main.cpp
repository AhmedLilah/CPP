#include <print>
#include <memory>
#include <string_view>

struct Data
{
        Data(const std::string& datum)
        : m_datum(datum)
        {
                std::println("[{}] Data::Data()", (void*)this);
        }
        ~Data() { std::println("[{}] Data::~Data()", (void*)this); }

        std::string_view datum() const { return m_datum; }

private:
        std::string m_datum;
};

struct Consumer
{
        void consume(std::unique_ptr<Data> data)
        {
                std::println("[CONSUMER] got the data: Â«{}Â»", data->datum());
        }
};

struct Borrower
{
        void borrow(std::unique_ptr<Data>&& data)
        {
                std::println("[BORROWER] got the data: Â«{}Â»", data->datum());

                // I might steal
                if (m_moocher)
                {
                        // and I will!
                        auto data_is_mine_now = std::move(data);
                }
        }

        void setBadWill() { m_moocher = true; }

private:
        bool m_moocher { false };
};

struct Producer
{
        Producer(Borrower& borrower, Consumer& consumer)
                : m_borrower(borrower)
                , m_consumer(consumer)
        {
        }

        void produce()
        {
                std::println("[PRODUCER] producing some data...");
                m_data = std::make_unique<Data>("Hello, World!");

                std::println("[PRODUCER] lending the data...");
                m_borrower.borrow(std::move(m_data));

                std::println("[PRODUCER] data should be mine again, checking... {}", (m_data != nullptr));

                if (!m_data)
                        {
                                std::println("[PRODUCER] what a dishonest borrower! \n\tIf I'll give m_data to the consumer, it will crash!");
                        }
                else
                {
                        m_consumer.consume(std::move(m_data));
                }

                std::println("[PRODUCER] m_data should be nullptr now, checking... {}", (m_data == nullptr));
        }

private:
        std::unique_ptr<Data> m_data;

        Borrower& m_borrower;
        Consumer& m_consumer;
};

int main()
{
        Borrower borrower;
        Consumer consumer;

        std::println("\n=== First run ===");
        Producer producer(borrower, consumer);
        producer.produce();

        std::println("\n=== Second run ===");
        borrower.setBadWill();
        producer.produce();

        return 0;
}
